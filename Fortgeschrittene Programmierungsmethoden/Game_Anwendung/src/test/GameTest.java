package test;

import Controller.GameController;
import Repo.InMemoryRepo;
import model.Trophy;
import model.TrophyTypes;
import model.VideoGame;
import org.junit.jupiter.api.Assertions;
import org.junit.jupiter.api.BeforeEach;
import org.junit.jupiter.api.Test;



public class GameTest {
    private InMemoryRepo<VideoGame> videoGameRepo;
    private InMemoryRepo<Trophy> trophyRepo;
    private GameController gameController;

    @BeforeEach
    public void setUp() {
        videoGameRepo = new InMemoryRepo<>();
        trophyRepo = new InMemoryRepo<>();
        gameController = new GameController(videoGameRepo, trophyRepo);
    }

    @org.junit.jupiter.api.Test
    public void testAddGameUnique() {
        gameController.addGame("Super Mario");
        Assertions.assertEquals(1, videoGameRepo.getAll().size());
        Assertions.assertEquals("Super Mario", videoGameRepo.getAll().get(0).getName());


        gameController.addGame("Super Mario");
        Assertions.assertEquals(1, videoGameRepo.getAll().size());
    }

    @org.junit.jupiter.api.Test
    public void testAddTrophyToGame() {
        gameController.addGame("Super Mario");
        gameController.addTrophyToGame("Super Mario", "First Steps", "Complete the first level", TrophyTypes.GOLD);
        VideoGame game = videoGameRepo.getAll().get(0);
        Assertions.assertEquals(1, game.getTrophyList().size());
        Assertions.assertEquals("First Steps", game.getTrophyList().get(0).getTitle());
        Assertions.assertEquals(1, trophyRepo.getAll().size());
        Assertions.assertEquals("First Steps", trophyRepo.getAll().get(0).getTitle());
    }

    @org.junit.jupiter.api.Test
    public void testDeleteTrophyFromGame() {
        gameController.addGame("Super Mario");
        gameController.addTrophyToGame("Super Mario", "First Steps", "Complete the first level", TrophyTypes.GOLD);
        gameController.deleteTrophyFromGame("Super Mario", "First Steps");
        VideoGame game = videoGameRepo.getAll().get(0);
        Assertions.assertEquals(0, game.getTrophyList().size());
        Assertions.assertEquals(0, trophyRepo.getAll().size());
    }

    @org.junit.jupiter.api.Test
    public void testUpdateGame() {
        gameController.addGame("Super Mario");
        gameController.updateGame("Super Mario", "Super Mario Odyssey");
        Assertions.assertEquals(1, videoGameRepo.getAll().size());
        Assertions.assertEquals("Super Mario Odyssey", videoGameRepo.getAll().get(0).getName());
    }

    @Test
    public void testDeleteGame() {
        gameController.addGame("Super Mario");
        gameController.deleteGame("Super Mario");
        Assertions.assertEquals(0, videoGameRepo.getAll().size());
    }
}
