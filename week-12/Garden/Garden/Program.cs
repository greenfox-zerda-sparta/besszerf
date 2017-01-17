using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

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
