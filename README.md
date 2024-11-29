# IPCA-POO-TP1
Class definition and test for a simulation of park management system.

## Intro
The project aims to simulate a park management system that includes: 
- Vehicle registration (entry and exit)
- Ticket calculation (after exit only) 
- Presents the occupationof the park
- Finds if a vehicle is parked 
- Consults the history of a vehicle in the park

## Running the tets
To run the tests, access the path with the mains designed for them:

```bash
cd main_tests
```

Run the *Makefile* inside with command:

```bash
make <option>
```

The options available are: 
- tall -> create the time class test
- pall -> create a park class test, the other classes are required for park to work
- vall -> create a vehicle and registration class test

The main in the main project folder may contain other tests that are not represented here due to time constraints. Please, feel free to uncomment and test by using the 'make' command again using the following options:
- call -> clean and all rules applied directly, creates the program "teste.exe"
- all -> creates the program "teste.exe" if no need to clean exists

#### NOTES

Sometimes, for both usecases, ```make builddir``` may be required, as it clean attempts to find it, and may fail if it doesn't exist.