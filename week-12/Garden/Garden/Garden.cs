using System;
using System.Collections.Generic;

namespace Garden
{
    class Garden
    {

        public Garden()
        {
            PlantsList = new List<Plants>();
        }
        private List<Plants> PlantsList;

        public void AddPlants(string color, string type)
        {
            if (type == "Tree")
            {
                PlantsList.Add(new Tree(color));
            }
            else if (type == "Flower")
            {
                PlantsList.Add(new Flower(color));
            }
        }

        public void displayState()
        {
            foreach (var Plant in PlantsList)
            {
                string state = "The " + Plant.Color + " " + Plant.Type;
                state += (Plant.NeedsWater() ? " needs water." : " doesn't need water.");
                Console.WriteLine(state);
            }
        }

        private int countThirstyPlants()
        {
            int numOfThirstyPlants = 0;
            foreach (var Plant in PlantsList)
            {
                if (Plant.NeedsWater())
                {
                    ++numOfThirstyPlants;
                }
            }
            return numOfThirstyPlants;
        }

        public void Watering(double amountOfWater)
        {
            Console.WriteLine();
            Console.WriteLine("Watering with {0}", amountOfWater);
            int numOfThirstyPlants = countThirstyPlants();

            foreach (var Plant in PlantsList)
            {
                if (Plant.NeedsWater())
                {
                    Plant.Watering(amountOfWater / numOfThirstyPlants);
                }
            }
        }
    }
}
