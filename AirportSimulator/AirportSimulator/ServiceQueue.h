#ifndef SERVICE_Q_H_
#define SERVICE_Q_H_

#include <queue>
#include "Plane.h"
#include "LandingQueue.h"
#include "DepartureQueue.h"
#include "Random.h"

extern Random my_random; // Enables us to access the global variable declared in Simulator.h

						 /** The service queue takes a plane from the landing queue and adds it to its queue.
						 When a plane in service queue has finished being serviced, it will be placed in the departure queue.
						 */
class ServiceQueue 
{

private:
	int min_service_time, max_service_time;  // range of service times
	LandingQueue *landing_queue;             // pointer to the landing queue
	DepartureQueue *departure_queue;         // pointer to the departure queue
	std::queue<Plane *> the_queue;           // queue of planes (just ONE) in the service queue
public:
	ServiceQueue() {}

	void set_service_times(int min_service_time, int max_service_time) 
	{
		this->min_service_time = min_service_time;
		this->max_service_time = max_service_time;
	}

	void set_landing_queue(LandingQueue *landing_queue) 
	{
		this->landing_queue = landing_queue;
	}

	void set_departure_queue(DepartureQueue *departure_queue)
	{
		this->departure_queue = departure_queue;
	}

	void update(int clock)
	{
		// there is a plane at the gate
		if (!the_queue.empty())
		{

			Plane *plane = the_queue.front();

			// check if a plane is ready to move from the service queue to the departure queue
			if ((clock - plane->start_service_time) > plane->service_time) 
			{
				// FIXME: remove plane from the service queue
				the_queue.pop();

				// FIXME: update the enter_departure_time attribute for the plane
				// sets the departure time to the time before the plane departs and the service time
				plane->enter_departure_time = clock - plane->start_service_time;
				departure_queue->the_queue.push(plane);
			}
		}

		// the gate is empty - ready to serve!
		if (the_queue.empty())
		{

			// move a plane from the landing queue to the service queue
			if (!landing_queue->the_queue.empty())
			{

				Plane *plane = landing_queue->the_queue.front();
				landing_queue->the_queue.pop();

				// FIXME: calculate the wait time of the plane in the landing queue
				int waitTime = 0; // sets the wait time to 0
								// waittime = is the diffrence of the current time to the arrival of the plane



								// FIXME: update total_wait and num_served for the landing queue

				waitTime = clock - plane->arrival_time;
				landing_queue->num_served++; // num_served is incremeneted because the the plane has 

				// adds the wait time for the plane with the rest of the wait times 
				landing_queue->total_wait += waitTime;


				// FIXME: update the start_service_time attribute for the plane
				// the serive time is set to be equal to the current time
				plane->start_service_time = clock;

				/* FIXME: compute a random service time for the plane between min_service_time and max_service_time
				HINT: You can use my_random.next_int(n) to get a random value between 0 and n.  This will help
				you determine a random number within the range of service times.
				*/
				double randomValue = 0;
				do {
					randomValue = (my_random.next_int(max_service_time)); //this will find the value that is less than the maxiumum or greater than the minimum

				} while (!(randomValue < min_service_time));
				
					plane->service_time = randomValue; // this sets the service time of the plane to a random number value on which the plane will be served.
				
				// FIXME: add the plane to the service queue
						the_queue.push(plane); // adds a new plane to the queue
					
				
			}
		}
	}

};

#endif