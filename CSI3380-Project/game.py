import pygame
import sys
import random

pygame.init()

pygame.font.init()
my_font = pygame.font.SysFont('Comic Sans MS', 30)

# Constants
SCREEN_WIDTH = 800
SCREEN_HEIGHT = 600
LEVEL_WIDTH = 10000
LEVEL_HEIGHT = SCREEN_HEIGHT

# Screen setup
screen = pygame.display.set_mode((SCREEN_WIDTH, SCREEN_HEIGHT))
pygame.display.set_caption("Simple Platformer")

# Player setup
PLAYER_SIZE = (25, 25)
PLAYER_COLOR = (255, 0, 0)
GRAVITY = 0.5
SPEED = 7.5
JUMP_STRENGTH = 13.5
player = pygame.Rect(20, SCREEN_HEIGHT // 2, *PLAYER_SIZE)
player_speed_x = 0
player_speed_y = 0
on_ground = False
direction = 'none'

# Platforms
NUM_PLATFORMS = 5
PLATFORM_WIDTH = 200
PLATFORM_HEIGHT = 30
PLATFORM_SIZE = (PLATFORM_WIDTH, PLATFORM_HEIGHT)
platforms = [pygame.Rect(200, 450, 50, 30), #Single
    
             pygame.Rect(600, 450, *PLATFORM_SIZE), #Large stairs
             pygame.Rect(800, 350, *PLATFORM_SIZE),
             pygame.Rect(1000, 250, *PLATFORM_SIZE),
             pygame.Rect(1200, 150, *PLATFORM_SIZE),
             
             pygame.Rect(1800, 525, *PLATFORM_SIZE), #Large staggered
             pygame.Rect(2000, 400, *PLATFORM_SIZE),
             pygame.Rect(1800, 275, *PLATFORM_SIZE),
             pygame.Rect(2000, 150, *PLATFORM_SIZE),
             
             pygame.Rect(2400, 450, 50, 30), #Small stairs
             pygame.Rect(2600, 375, 50, 30),
             pygame.Rect(2800, 300, 50, 30),
             pygame.Rect(3000, 225, 50, 30),
             pygame.Rect(3200, 150, 50, 30),

             pygame.Rect(3600, 525, 50, 30), #Small staggered
             pygame.Rect(3800, 400, 50, 30),
             pygame.Rect(3600, 275, 50, 30),
             pygame.Rect(3800, 150, 50, 30),
             pygame.Rect(3600, 50, 50, 30)
             ]


# Coins
COIN_SIZE = (15, 15)
COIN_COLOR = (255, 215, 0)  # Gold color
coins = [pygame.Rect(210, 260, *COIN_SIZE),  #Single
         pygame.Rect(1350, 125, *COIN_SIZE), #Large stairs
         pygame.Rect(2150, 125, *COIN_SIZE), #Large staggered
         pygame.Rect(3220, 125, *COIN_SIZE), #Small stairs
         pygame.Rect(3620, 25, *COIN_SIZE)   #Small staggered 
         ] 

count_collected_coins = 0
total_coins = len(coins)

camera_offset = 0

end_time = None

# Game loop
running = True
while running:
    level_position_x = player.x + camera_offset
    level_position_y = player.y
    #print(int(level_position_x), level_position_y)

    time = round((pygame.time.get_ticks() / 1000), 1)
    timer_text = my_font.render(str(time), True, (255, 255, 255))
    coin_text = my_font.render(f'Coins: {count_collected_coins} / {total_coins}', True, (255, 255, 255))

    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False

    # Key presses
    keys = pygame.key.get_pressed()
    if keys[pygame.K_LEFT]:
        player_speed_x = -SPEED
        direction = 'left'
    elif keys[pygame.K_RIGHT]:
        player_speed_x = SPEED
        direction = 'right'
    else:
        player_speed_x = 0

    # Jumping
    if keys[pygame.K_SPACE] and on_ground:
        player_speed_y = -JUMP_STRENGTH
        on_ground = False

    # Apply gravity
    player_speed_y += GRAVITY
    player.x += player_speed_x
    player.y += player_speed_y
    on_ground = False

    # Collision detection
    for platform in platforms:
        if player.colliderect(platform.move(-camera_offset, 0)) and player_speed_y > 0:
            player.bottom = platform.top  # Adjust player position to be on top of the platform
            player_speed_y = 0
            on_ground = True
            break  # Stop checking after the first collision to avoid conflicting resolutions

    # Check for coin collection
    for coin in coins[:]:  # Iterate over a copy of the list
        if player.colliderect(coin.move(-camera_offset, 0)):
            coins.remove(coin)
            count_collected_coins += 1

    # Check if player is on the bottom of the screen
    if player.bottom >= SCREEN_HEIGHT:
        player.bottom = SCREEN_HEIGHT
        player_speed_y = 0
        on_ground = True  # Player is on the ground

    # Screen boundaries
    if player.left < 0:
        player.left = 0

    if player.right > LEVEL_WIDTH:
        player.right = LEVEL_WIDTH

    if player.bottom > SCREEN_HEIGHT:
        player.bottom = SCREEN_HEIGHT
        player_speed_y = 0

    # Scrolling
    if player.right >= SCREEN_WIDTH * 3 / 4 and direction == 'right':
        scroll_x = min(SPEED, LEVEL_WIDTH - SCREEN_WIDTH - camera_offset)
        camera_offset += scroll_x
        player.x -= scroll_x
    elif player.left <= SCREEN_WIDTH / 4 and direction == 'left':
        scroll_x = min(SPEED, camera_offset)
        camera_offset -= scroll_x
        player.x -= scroll_x

    if count_collected_coins == total_coins:
        game_complete = True
        if end_time is None:
            end_time = time
    else:    
        game_complete = False

    # Drawing
    if game_complete == False:
        screen.fill((0, 0, 0))  # Clear screen
        pygame.draw.rect(screen, PLAYER_COLOR, player)  # Draw player

        for platform in platforms:
            adjusted_platform = platform.move(-camera_offset, 0) 
            pygame.draw.rect(screen, (0, 255, 0), adjusted_platform)  # Draw platforms

        for coin in coins:
            adjusted_coin = coin.move(-camera_offset, 0)
            pygame.draw.rect(screen, COIN_COLOR, adjusted_coin)

        screen.blit(timer_text, (10, 10))
        screen.blit(coin_text, (10, 40))
    else:
        # Game complete screen
        screen.fill((0, 0, 0))
        game_complete_text = my_font.render('You Win!', True, (255, 255, 255))
        end_time_text = my_font.render(f'Your time: {end_time}', True, (255, 255, 255))
        screen.blit(game_complete_text, (SCREEN_WIDTH // 2 - 100, SCREEN_HEIGHT // 2 - 50))
        screen.blit(end_time_text, (SCREEN_WIDTH // 2 - 100, SCREEN_HEIGHT // 2))


    pygame.display.flip()  # Update screen
    pygame.time.Clock().tick(60)  # 60 FPS

# Quit Pygame
pygame.quit()
sys.exit()