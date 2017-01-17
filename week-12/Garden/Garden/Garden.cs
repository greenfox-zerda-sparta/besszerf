using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
                state += (Plant.NeedsWater()? " needs water." : " doesn't need water.");
                Console.WriteLine(state);
            }
        }

        public void Watering(double amountOfWater)
        {
            Console.WriteLine();
            Console.WriteLine("Watering with {0}", amountOfWater);
            int numOfThirstyPlants = 0;
            foreach (var Plant in PlantsList)
            {
                if(Plant.NeedsWater())
                {
                    ++numOfThirstyPlants;
                }
            }
            foreach (var Plant in PlantsList)
            {
                if (Plant.NeedsWater())
                {
                    Plant.Watering(amountOfWater/numOfThirstyPlants);
                }
            }
        }
    }
}
