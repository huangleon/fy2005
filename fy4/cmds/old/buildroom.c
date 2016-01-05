inherit F_CLEAN_UP;
int check_legal_name(string name);
int check_legal_long(string name);
void enter_desc(object me,object gold,string s_title, int flag,string dir, string text);
#define SCORE_COST 5000
#define GOLD_COST  1000
#define MIN_EXP	100000
int main(object me, string arg)
{
	int flag;
	string stitle;
	string ltitle;
	string dir;
	object env;
	object gold;
        seteuid(getuid());
        if(!arg || sscanf(arg,"%s %s %d",dir,stitle,flag) != 3)
		return notify_fail("Ö¸Áî¸ñÊ½£º¡¡buildroom north ÎÒµÄÐ¡ÎÝ 0\n");
	if((int)me->query("score") < SCORE_COST)
		return notify_fail("ÄãµÄÆÀ¼Ûµã²»¹»"+chinese_number(SCORE_COST)+	"µã¡£\n");
        if((int)me->query("combat_exp") < MIN_EXP)
        	return notify_fail("ÄãµÄÊµÕ½¾­Ñé²»¹»¡££¨Ðè15¼¶£©\n");
	gold = present("gold_money",me);
		if(!gold) return notify_fail("ÄãÉíÉÏÃ»ÓÐ½ð×Ó¡£\n");
        if((int) gold->query_amount() < GOLD_COST)
        	return notify_fail("ÄãÉíÉÏÃ»ÓÐ"+chinese_number(GOLD_COST)+"Á½½ð×Ó¡£\n");
	if((int)me->query("created_room") > 3)
		return notify_fail("Äã²»¿ÉÔÙ½¨·¿ÁË£¡\n");
        
        env = environment(me);
        if(!env->query("owner") && (string)env->query("owner") != "public" 
	&& (string)env->query("owner") != (string) me->query("id"))
        	return notify_fail("Äã²»¿ÉÔÚÕâ½¨·¿£¡\n");
	if(check_legal_name(stitle))
		 me->edit( (: enter_desc , me,gold, stitle, flag, dir :) );
	return 1;
	
}
void enter_desc(object me,object gold, string s_title, int flag,string dir,string text)
{
string *direc= ({"north", "south", "east", "west", "northup", 
"southup", "eastup", "westup", "northdown",
"southdown", "eastdown", "westdown", "northeast", 
"northwest", "southeast", "southwest", "up", "down"});
	int i;
	int okey=0;
	object env;
	if(!check_legal_long(text)) return;
        for (i = 0; i < sizeof(direc); i++)
	if(direc[i] == dir) {okey=1; break;}
	if(okey)	
	{
	env = environment(me);
	if(env->query("exits/"+dir))
		{
		tell_object(me,"Õâ¸ö·½ÏòÒÑ¾­ÓÐ·¿ÎÝÁË£¡\n");
		return;
		}
// I think by now, we should checked all conditions,
// deduct the cost and go build it!
		gold->add_amount(-GOLD_COST);
		me->add("score",-SCORE_COST);
		BR_D->buildroom(me,flag,s_title,text,dir);
	}
	else
	{
		tell_object(me,"ÄãÒªÍùÄÄ¸ö·½Ïò½¨£¿\n");
		return;
	}
}

int check_legal_name(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 2) || (strlen(name) > 40 ) ) {
                write("¶Ô²»Æð£¬ÖÐÎÄÃû×Ö±ØÐëÊÇÒ»µ½¶þÊ®¸öÖÐÎÄ×Ö¡£\n");
                return 0;
        }
        while(i--) {
                if( name[i]<=' ' ) {
                        write("¶Ô²»Æð£¬ÖÐÎÄÃû×Ö²»ÄÜÓÃ¿ØÖÆ×ÖÔª¡£\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("¶Ô²»Æð£¬Ãû×Ö±ØÐèÊÇÖÐÎÄ¡£\n");
                        return 0;
                }
        }
        return 1;
}

int check_legal_long(string name)
{
        int i;
        i = strlen(name);
        if( (strlen(name) < 120) || (strlen(name) > 600 ) ) {
                write("¶Ô²»Æð£¬ÖÐÎÄÃèÊö±ØÐëÊÇÁùÊ®µ½Èý°Ù¸öÖÐÎÄ×Ö¡£\n");
                return 0;
        }
        while(i--) {
		if(name[i]==' ' || name[i] == '\n') continue;
                if( name[i]<' ' ) {
                        write("¶Ô²»Æð£¬ÖÐÎÄÃèÊö²»ÄÜÓÃ¿ØÖÆ×ÖÔª¡£\n");
                        return 0;
                }
                if( i%2==0 && !is_chinese(name[i..<0]) ) {
                        write("¶Ô²»Æð£¬ÃèÊö±ØÐèÊÇÖÐÎÄ¡£\n");
                        return 0;
                }
        }
        return 1;
}

int help (object me)
{
	write(@HELP
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m
[0;1;36mÖ¸Áî¸ñÊ½ : 	build <Ñ¶Ï¢>[0m
[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   

´ËÖ¸ÁîÈÃÍæ¼Ò½¨ÔìÒ»×ùÊôÓÚ×Ô¼ºµÄ·¿ÎÝ¡£

½¨ÔìÒ»Ëù·¿ÎÝµÄ»¨·ÑÎª5000ÆÀ¼Û¡¢1000Á½»Æ½ð¡£Ã¿¸öÍæ¼Ò×î¶à¿ÉÒÔ½¨
ÔìÈý¼äÎÝ×Ó¡£

µ±Íæ¼ÒÔÚ·çÔÆÖÐ´ïµ½Ò»¶¨µÄµØÎ»£¬ÓµÓÐ×ã¹»µÄ²Æ¸»ºÍÉùÍû£¬¾Í¿ÉÒÔÔÚ
·çÔÆ³ÇÒÔ±±µÄÉ½¹ÈÖÐ½¨Á¢ÊôÓÚ×Ô¼ºµÄ¿Õ¼ä¡£ÖÚ¶àÍæ¼Ò»¹¿ÉÒÔºÏ×÷£¬¹²
½¨Ò»¿éÇøÓò£¬ÓÃÓÚ×Ô¼ºµÄÃÅÅÉ»ò°ï»á¡£Ã¿¸ö¿Õ¼ä¿ÉÒÔÓÐ²»Í¬µÄÐÔÖÊ£¬
¿ÉÒÔÊÇ×Ô¼ºµÄË½ÈË×¡Õ¬£¨Ö»ÓÐÍæ¼Ò×Ô¼º¿ÉÒÔ½øÈë£©£¬Ò²¿ÉÒÔÊÇ°ïÅÉµÄ
Ë½µØ£¨Ö»ÓÐÍ¬ÅÉµÄÈË¿ÉÒÔ½øÈë£©£»¿ÉÒÔÊÇ½ûÖ¹´òÉ±µÄµØ·½£¬Ò²¿ÉÒÔÊÇ
ÎÞ·¨ÎÞÌìµÄµØ¶Î¡£·¿¼ä½¨ÉèÍê³ÉÖ®ºó£¬ËùÓÐµÄÐÔÖÊ£¬ÃèÊö¶¼²»¿ÉÒÔÔÙ
¸Ä±ä£¬ËùÒÔ´ó¼ÒÔÚÉè¶¨·¿¼äµÄÊ±ºòÒ»¶¨Òª¶à¼Ó¿¼ÂÇ£¬ÓÃÐÄÑ¡Ôñ¡£

ÖÆÔì·¿¼äµÄÏêÏ¸¿îÏîÈçÏÂ£º

buildroom <·½Ïò> <·¿¼äÃû³Æ> <±êÖ¾>

·½Ïò£º	·½ÏòÊÇ¶ÔÄãÏÖÔÚµÄÎ»ÖÃ¶øÑÔ£¬Èç¹û·½ÏòÊÇnorth£¬¾ÍÊÇËµÄãÒª
	ÔÚÏÖÔÚÒÔ±±µÄ·½Ïò½¨·¿¡£
·¿¼äÃû³Æ£ºÊÇÄãËù¿´µ½µÄ¼ò¶ÌÃèÊö¡£
±êÖ¾£º	ÄãËù½¨µÄ·¿¼äµÄÊôÐÔÈ«¶¼ÓÉ±êÖ¾À´¾ö¶¨¡£¿ÉÒÔÑ¡ÔñµÄ±êÖ¾ÓÐ£º
	1£º¿ÉÒÔÔÚ´Ë´æµµ¶øÇÒÏÂ´ÎÁ·ÏßÊ±ÔÚ´Ë´¦¿ªÊ¼¡£
	2£ºÖ»¿ÉÒÔÍæ¼Ò½øÈëµÄ¿Õ¼ä£¨²»¿É´ò×ø£©¡£
	4£º²»¿ÉÕ½¶·µÄ¿Õ¼ä£¨²»¿É´ò×ø£©¡£
	8£º²»¿ÉÓÐ·¨ÊõºÍÄ§ÊõµÄ¿Õ¼ä£¨²»¿É´ò×ø£©¡£
	16£ºÊÒÍâµÄ¿Õ¼ä£¨ËùÓÐÈË¶¼¿ÉÒÔ½øÈë£¬Èç¹ûÃ»ÓÐÕâ¸ö16£¬Æä
		ËûÍæ¼Ò²»¿ÉÒÔÈëÄÚ£©¡£
	512£ºÖ»¿ÉÒÔ×Ô¼º½øÈëµÄ¿Õ¼ä¡£
	1024£ºÖ»¿ÉÒÔÍ¬ÃÅµÄÈËÎï½øÈëµÄ¿Õ¼ä¡£
	2048£º¿ÉÒÔÑûÇë£¨invite£©±ðÈË½øÈëµÄ¿Õ¼ä¡£
	
buildroom north Ð¡Ä¾ÎÝ 2
¾Í»áÔÚÒÔ±±µÄµØ·½½¨ÖþÒ»¼äÐ¡ÎÝÃûÎª¡°Ð¡Ä¾ÎÝ¡±£¬Ä¾ÎÝµÄÐÔÖÊÊÇÖ»¿É
ÒÔÈÃÍæ¼ÒÃÇ½øÈë¡£

buildroom southdown Á·Îä³¡ 1040
¾Í»áÔÚÄÏ±ßµÍ´¦½¨Á¢Ò»¸öÊÒÍâ¿Õ¼äÃûÎª¡°Á·Îä³¡¡±£¬´Ë³¡µÄÐÔÖÊÊÇÊÒ
Íâ£¨16£©ºÍÖ»ÊÇÍ¬ÃÅµÄÈË£¨1024£©²Å¿ÉÒÔ½øÈë£¨1024+16=1040£©¡£

buildroom eastup »Æ½ðÎÝ 525
¾Í»áÔÚ¶«·½¸ß´¦½¨Á¢Ò»¸ö·¿¼äÃûÎª¡°»Æ½ðÎÝ¡±£¬´ËÎÝµÄÐÔÖÊÊÇÏÂ´Î
¿ÉÔÚ´ËÁ¬Ïß½øÈë£¨1£©£¬²»¿É´òÉ±£¨4£©£¬²»¿ÉÊ©Õ¹Ä§·¨£¨8£©£¬ºÍÖ»
¿ÉÒÔ×Ô¼º½øÈë£¨512£©£¨1£«4£«8£«512£½525£©¡£

µ±¼¸¸öÈËÅäºÏ½¨Á¢Á¬ÔÚÒ»ÆðµÄ·¿¼äÊ±£¬ÓÐ±ØÒªÓÃsetownerÕâ¸öÖ¸Áî£¬½«
·¿¼äµÄÖ÷ÈËÔÝÊ±¶¨ÎªËûÈË¡£

[0;1;37m©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤©¤[0m   
HELP
	);
	return 1;
}
