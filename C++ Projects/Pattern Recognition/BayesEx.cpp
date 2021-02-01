/* Example: Suppose you are a hospital manager, and you are considering the use of a new method to 
diagnose a rare form of bowel syndrome. You know that only 0.1% of the population suffers from that 
disease. You also know that if a person has the disease, the test has 99% of chance of turning out 
positive. If the person doesn’t have the disease, the test has a 98% chance of turning negative.

Question: How feasible is this diagnostics method? That is, given that a test turned out positive,
what are the chances of the person really having the disease?
*/

#include<bits/stdc++.h>
using namespace std;

//The Baye's Theorem Function
double Bayes(double y_given_x, double x, double y) // P(X|Y) = [P(Y|X) * P(X)] / P(Y)
{
    return (y_given_x*x)/y;
}

int main()
{
    /* Solution: Let’s say that event DIS is having the disease, and event POS is getting a positive test.
    The description of the problem tells us that:
    */
    double dis = 0;    //P(DIS) =  (population with the disease)
    cout<<"Enter the Percentage of population with disease: ";
    cin>>dis;
    dis /= 100;
    double dis_inv = 1 - dis;  // P(DIS') =  (population without the disease, so complement of event DIS)
    double pos_dis = 0; // P(POS|DIS) =  (positive test given patient has disease)
    cout<<"\nEnter the Percentage that the result will be POSITIVE if a person has the disease: ";
    cin>>pos_dis;
    pos_dis /= 100;
    double pos_dis_inv = 1 - pos_dis;  // P(POS|DIS') = (positive test given patient doesn't have disease)
    double neg_dis_inv = 0;  // P(POS'|DIS') =  (negative test given patient doesn't have the disease)
    cout<<"\nEnter the Percentage that the result will be NEGATIVE if a person doesn't have the disease: ";
    cin>>neg_dis_inv;
    neg_dis_inv /= 100;
    double neg_dis = 1 - neg_dis_inv; // P(POS'|DIS) =  (negative test given patient has disease)

    /*To solve the problem we want to find P(DIS|POS).
    Using the Baye's Theorem we require P(POS|DIS), P(DIS) and P(POS).
    We have all the values except P(POS).
    P(POS) is union of the probability of getting the positive result on having the disease and the probability
    of getting the positive result even though not having the disease.
    */
    double pos = (dis*pos_dis) + (dis_inv*pos_dis_inv);  //So P(POS) = P(DIS)P(POS|DIS) + P(DIS')P(POS|DIS')
    // Now using the Baye's Theorem to calculate the resultant Probability: 
    double dis_pos = Bayes(pos_dis, dis, pos);
    cout<<"\n\nTherefore, there is a "<<dis_pos<<" chance that the person has the disease if the test turned out positive.";

    return 0;
}