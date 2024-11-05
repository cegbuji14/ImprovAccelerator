#include<iostream>
#include<string>
using namespace std;

//Circle of Fifths Library. 
// eventually implement with doubly linked list for all coming from the key of C major
//2d array approach for now

/*Pentatonic scales for 1,4, & 5 chords for a relative minor/major keys.
  For minor: 1 = (1) aeolian
             4 = (4) dorian
             5 = (5) phyrgian
*/

// major keys
string major_keys[12][7] = 
{{"Cmaj", "Dmin", "Emin", "Fmaj", "Gmaj", "Amin","Bdim"},//C major
{"Gmaj", "Amin", "Bmin", "Cmaj", "Dmaj", "Emin","F#dim"},//G major
{"Dmaj", "Emin", "F#min", "Gmaj", "Amaj", "Bmin","C#dim"},//D major
{"Amaj", "Bmin", "C#min", "Dmaj", "Emaj", "F#min","G#dim"},//A major
{"Emaj", "F#min", "G#min", "Amaj", "Bmaj", "C#min","D#dim"},//E major
{"Bmaj", "C#min", "D#min", "Emaj", "F#maj", "G#min","A#dim"},//B major
{"Gbmaj", "G#min", "A#min", "Bmaj", "C#maj", "D#min","Fdim"},//Gb major
{"Dbmaj", "Ebmin", "Fmin", "Gbmaj", "Abmaj", "Bbmin","Cdim"},//Db major
{"Abmaj", "Bbmin", "Cmin", "Dbmaj", "Ebmaj", "Fmin","Gdim"},//Ab major
{"Ebmaj", "Fmin", "Gmin", "Abmaj", "Bbmaj", "Cmin","Ddim" },//Eb major
{"Bbmaj", "Cmin", "Dmin", "Ebmaj", "Fmaj", "Gmin","Adim" },//Bb major
{"Fmaj", "Gmin", "Amin", "Bbmaj", "Cmaj", "Dmin","Edim" }};//F major

//minor keys
string minor_keys[12][7] = {{"Amin", "Bdim", "Cmaj", "Dmin", "Emin", "Fmaj","Gmaj" },//A minor
{"Emin", "F#dim", "Gmaj", "Amin", "Bmin", "Cmaj","Dmaj" },//E minor
{"Bmin", "C#dim", "Dmaj", "Emin", "F#min", "Gmaj","Amaj" },//B minor
{"F#min", "G#dim", "Amaj", "Bmin", "C#min", "Dmaj","Amaj" },//Gb/F# minor
{"C#min", "D#dim", "Emaj", "F#mi n", "G#min", "Amaj","Bmaj" },//Db/C# minor
{"G#min", "A#dim", "Bmaj", "C#min", "D#min", "Emaj","F#maj" },//Ab/G# minor
{"Ebmin", "Fbdim", "Gbmaj", "Abmin", "Bbmin", "Bmaj","Dbmaj" },//D#/Eb minor
{"Bbmin", "Cdim", "Dbmaj", "Ebmin", "Fmin", "Gbmaj","Abmaj" },//Bb/A# minor
{"Fmin", "Gdim", "Abmaj", "Bbmin", "Cmin", "Dbmaj","Ebmaj" },//F minor
{"Cmin", "Ddim", "Ebmaj", "Fmin", "Gmin", "Abmaj","Bbmaj" },//C minor
{"Gmin", "Adim", "Bbmaj", "Cmin", "Dmin", "Ebmaj","Fmaj" },//G minor
{"Dmin", "Edim", "Fmaj", "Gmin", "Amin", "Bbmaj","Cmaj" }};//D minor

// major blues keys
string majblues_keys[12][7] = 
{{"Cblues", "Dmin", "Emin", "Fmaj", "Gmaj", "Amin","Bdim"},//C major
{"Gblues", "Amin", "Bmin", "Cmaj", "Dmaj", "Emin","F#dim"},//G major
{"Dblues", "Emin", "F#min", "Gmaj", "Amaj", "Bmin","C#dim"},//D major
{"Ablues", "Bmin", "C#min", "Dmaj", "Emaj", "F#min","G#dim"},//A major
{"Eblues", "F#min", "G#min", "Amaj", "Bmaj", "C#min","D#dim"},//E major
{"Bblues", "C#min", "D#min", "Emaj", "F#maj", "G#min","A#dim"},//B major
{"Gbblues", "G#min", "A#min", "Bmaj", "C#maj", "D#min","Fdim"},//Gb major
{"Dbblues", "Ebmin", "Fmin", "Gbmaj", "Abmaj", "Bbmin","Cdim"},//Db major
{"Abblues", "Bbmin", "Cmin", "Dbmaj", "Ebmaj", "Fmin","Gdim"},//Ab major
{"Ebblues", "Fmin", "Gmin", "Abmaj", "Bbmaj", "Cmin","Ddim" },//Eb major
{"Bbblues", "Cmin", "Dmin", "Ebmaj", "Fmaj", "Gmin","Adim" },//Bb major
{"Fblues", "Gmin", "Amin", "Bbmaj", "Cmaj", "Dmin","Edim" }};//F major

//minor blues keys
string minblues_keys[12][7] = {{"Amblues", "Bdim", "Cmaj", "Dmin", "Emin", "Fmaj","Gmaj" },//A minor
{"Emblues", "F#dim", "Gmaj", "Amin", "Bmin", "Cmaj","Dmaj" },//E minor
{"Bmblues", "C#dim", "Dmaj", "Emin", "F#min", "Gmaj","Amaj" },//B minor
{"F#mblues", "G#dim", "Amaj", "Bmin", "C#min", "Dmaj","Amaj" },//Gb/F# minor
{"C#mblues", "D#dim", "Emaj", "F#mi n", "G#min", "Amaj","Bmaj" },//Db/C# minor
{"G#mblues", "A#dim", "Bmaj", "C#min", "D#min", "Emaj","F#maj" },//Ab/G# minor
{"Ebmblues", "Fbdim", "Gbmaj", "Abmin", "Bbmin", "Bmaj","Dbmaj" },//D#/Eb minor
{"Bbmblues", "Cdim", "Dbmaj", "Ebmin", "Fmin", "Gbmaj","Abmaj" },//Bb/A# minor
{"Fmblues", "Gdim", "Abmaj", "Bbmin", "Cmin", "Dbmaj","Ebmaj" },//F minor
{"Cmblues", "Ddim", "Ebmaj", "Fmin", "Gmin", "Abmaj","Bbmaj" },//C minor
{"Gmblues", "Adim", "Bbmaj", "Cmin", "Dmin", "Ebmaj","Fmaj" },//G minor
{"Dmblues", "Edim", "Fmaj", "Gmin", "Amin", "Bbmaj","Cmaj" }};//D minor

void ImprovSuggestMajorKey(string key, string genre){
  for (int i = 0; i < 12;i++){
    if (genre == "Blues" && majblues_keys[i][0] == key){
      cout << "\n\nWhen playing a blues number in " << majblues_keys[i][0] << ". Major pentatonic and blues scales are always safe choices. Consider switching modalities too.\nHappy playing!";
    }
    if (major_keys[i][0] == key && genre == "Jazz"){
      cout << "\n\nWhile jazz is not so much of a specific scale thing there are scales that can be used to assist. I'd firstly suggest familiarizing yourself with chord tones and harmony. Arpeggios will be your friend as well.\n\n" << "Some scales to use include " << key << " and all of its modes. In jazz scale choices are often based on the chords being played over.\n" << "You may play dorian over a "<< major_keys[i][1] << "chord, mixolydian over a" << major_keys[i][4] << " and you may play the " << major_keys[i][0] << " scale over the " << major_keys[i][0] << " chord.\n" << "Another approach could be choosing scales based on chord substitution.\nTake " << major_keys[i][1] << ", " << major_keys[i][4] << ", and " << major_keys[i][0] << " and substitute them with V7 chords and choose scales accordingly.\nHappy playing!";
    }
    if (major_keys[i][0] == key  && ((genre == "Gospel")||(genre =="Pop"))){
      cout << "\n\nFor " << genre <<" in the key of " << key << ". The " << major_keys[i][0] << " scale will be your friend. As well as the " << major_keys[i][0] << " pentatonic and blues scale.\nHappy Playing";
    }
    if (major_keys[i][0] == key && ((genre == "Rock") || (genre == "R&B"))){
      cout << "\n\nCan't go wrong with the "  << key << "major or major pentatonic or scale.\n" << "Experiment with the " << major_keys[i][0][0] << "blues scale's (minor & major) as well\n\n" << "Happy playing!";
    }
    if (minor_keys[i][0] == key && ((genre == "Country") || (genre == "Funk" ))){
      cout << "\n\nWith " << genre << " I think a little goes a long way.\nThink it is not so much the notes that you play but instead how you play them.Keep it simple.\n" << key << "blues and penatonic for the win!\n Happy playing!";
    }
  }
}

void ImprovSuggestMinorKey(string key, string genre){
  for(int i = 0; i < 12; i++){
    if (genre == "Blues" && minblues_keys[i][0] == key){
      cout << "\n\nWhen playing a blues number in " << minblues_keys[i][0] << ", minor pentatonic and blues scales are always safe choices.\n Consider switching modalities too.\nHappy playing!";
    }
    if (minor_keys[i][0] == key && ((genre == "Rock") || (genre == "R&B"))){
      cout << "\n\nCan't go wrong with the "  << key << " or minor pentatonic scale. \n" << "Mixing in some  " << minor_keys[i][3] << " and " << minor_keys[i][4] << " will also give you a different feel and make your playing a little more colorful too. \n" << "Experiment with the "<< minor_keys[i][0] << " blues scale's (minor & major) as well.\n\n" << "Happy playing!";
    }
    if (minor_keys[i][0] == key && ((genre == "Country") || (genre == "Funk" ))){
      cout << "\n\nWith " << genre << " I think a little goes a long way.\nThink it is not so much the notes that you play but instead how you play them.Keep it simple.\n" << key << " blues and penatonic for the win!\n Happy playing!";
    }
    if (minor_keys[i][0] == key && genre == "Jazz"){
      cout << "\n\nWhile jazz is not so much of a specific scale thing there are scales that can be used to assist. I'd firstly suggest familiarizing yourself with chord tones and harmony. Arpeggios will be your friend as well.\n\n" << "Some scales to use include " << key << " and all of its modes. In jazz scale choices are often based on the chords being played over.\n" << "You may play locrian over a "<< minor_keys[i][1] << "(min7b5), " << minor_keys[i][4][0] << "mixolydian over a " << minor_keys[i][4] << "(V7), and you may play the " << minor_keys[i][0] << " scale over a" << minor_keys[i][0]<< "(min7) chord.\n" << "Another approach could be using the " << minor_keys[i][0] << "minor blues scale.\n Happy ending!";
    }
    if (minor_keys[i][0] == key  && ((genre == "Gospel")||(genre =="Pop"))){
      cout << "\n\nFor " << genre <<" in the key of " << key << ". The " << minor_keys[i][0] << " scale will be your friend. As well as the " << minor_keys[i][0] << " pentatonic and blues scale.\nHappy Playing";
    }
  }

    
  
}

int main()
{
  string keyInput, genreInput;
  cout << "Input key of the song in following format (case sensitive).\nEmaj\nEmin\nEblues\nEmblues\n\n";
  cout << "For Db minor use C#min/C#mblues\nFor Gb minor use F#min/F#mblues\nFor Ab minor use G#min/G#mblues\n\n";
  cout << "All #/b major keys are denoted with b\n\n";
  cin >> keyInput;
  cout << "\n\nInput Genre name. Genre must be on list below (case sensitive).\n\n";
  cout << "Rock\nBlues\nJazz\nR&B\nGospel\nPop\nCountry\nFunk\n\n";
  cin >> genreInput;

  ImprovSuggestMajorKey(keyInput, genreInput);
  ImprovSuggestMinorKey(keyInput, genreInput);
  
}
