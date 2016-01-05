//	Silencer@fy4 workgroup

#include <ansi.h>
inherit F_CLEAN_UP;

int main (object me, string arg)
{
	int iron, i,duration;
	string msg;
	string *word;
	string *temp = ({"an", "ba", "hong", "ma", "mi", "ni" });
	string *ctemp = ({"б║ЖЖб╗","б║░╚б╗","б║▀шб╗","б║┬яб╗","б║▀фб╗","б║─╪б╗"});
	
	if (me->query("class")!= "lama")
		return notify_fail("╓╗╙╨┤є╒╤╡▄╫╙▓┼─▄╨√б║╢■╫╓╒ц╤╘б╗\n");
		
	iron = me->query_skill("kwan-yin-spells",1);
	if (iron < 170)
		return notify_fail("б║╢■╫╓╒ц╤╘б╗╨ш╥к170╝╢╣█╥Ї┴∙╫╓├ў╓фбг\n");

	if (!arg)
		return notify_fail("─у╧╓╘┌╫╝▒╕╡─╢■╫╓╒ц╤╘╬кг║"+ me->query("marks/pfm/2word")+"\n");
	
/*	if (me->is_busy())
		return notify_fail("─у╧╓╘┌╒¤├жгм╬▐╖и╛▓╦╝╒ц╤╘бг\n");
			
	if(me->is_fighting() )
		return notify_fail("б║╢■╫╓╒ц╤╘б╗▓╗─▄╘┌╒╜╢╖╓╨╝╟╥фбг\n");
*/
	
	word = allocate(2);
	
	if (sscanf(arg,"%s+%s",word[0],word[1])!=2)
		return notify_fail("╢■╫╓╒ц╤╘╔ш╓├╡─╕ё╩╜▓╗╢╘гм╟ы▓╬┐┤help 2word\n");
	
	message_vision(HIY"$N"NOR+HIY"╡°╫°╘┌╡╪гм╦л═╚┼╠┬ггм║╧╩о─ю╡└г║╥╗╟╨╙╨╬к╖ибб╚ч├╬╗├┼▌╙░  ╚ч┬╢╥р╚ч╡чбб╙ж╫ў╚ч╩╟╣█\n"NOR,me);
	
	for (i=0;i<2;i++){
		if (member_array(word[i],temp)==-1)
			return notify_fail(word[i]+"▓╗╩╟┐╔╝╟╥ф╡─┴∙╫╓╒ц╤╘╓о╥╗бг\n");
		write(" ╡┌" + chinese_number(i+1) +"╕Ў╒ц╤╘╩╟г║" + word[i] +"\n");	
	}
		
	me->set("marks/pfm/2word",arg);
	
	
	return 1;
}


int help(object me)
{
write(@HELP
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m
[0;1;36m╓╕┴ю╕ё╩╜ : 	2word[0m
[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   

┤є╒╤╕▀╔о╨▐┴╢╣█╥Ї├ў╓ф╡╜170╝╢╥╘╔╧║єгм┐╔═м╩▒╦╠│Ў╩¤╫╓╒ц╤╘гм
╡л╩╟гм╘┌╩╣╙├╓о╟░▒╪╨ы╛▓╦╝╞м┐╠╝╟╥фбг

╕ё╩╜╛┘└¤г║бб2word an+an
╙╓╚чг║	   2word an+ni

╩╣╙├cast 2word ▒у┐╔╜л╝╟╥ф╫б╡─╒ц╤╘═м╩▒╦╠│Ўбг

╢╘╙┌╢■╫╓╒ц╤╘└┤╦╡гм║─╖╤╡─╖и┴ж╫ю╢р▓╗│м╣¤350гм╘ь│╔╡─╫╘╬╥├ж┬╥
╫ю╢р▓╗│м╣¤4бг

[0;1;37mйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйдйд[0m   
HELP
    );
    return 1;
}