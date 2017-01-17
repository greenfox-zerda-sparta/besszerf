namespace Garden
{
    class Program
    {
        static void Main(string[] args)
        {
            Garden myGarden = new Garden();
            myGarden.AddPlants("yellow", "Flower");
            myGarden.AddPlants("blue", "Flower");
            myGarden.AddPlants("purple", "Tree");
            myGarden.AddPlants("orange", "Tree");
            myGarden.displayState();
            myGarden.Watering(40);
            myGarden.displayState();
            myGarden.Watering(70);
            myGarden.displayState();
        }
    }
}
