// jinhuzi.c
inherit NPC;

#include <ansi.h>
int *stat =({0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0});
int *low_index = ({});
void pay_him(object who, int amount);
void clear_stat();
void pre_cal();
void create()
{
	set_name("½ð´óºú×Ó", ({ "jin huzi", "jin"}) );
	set("title","½ðºú×Ó¶Ä·» ÀÏ°å");
        set("gender", "ÄÐÐÔ" );
	set("age", 48);
	set("long",
"ËûÊÇ¸öÒÂÉÑ´©µÃºÜ»ªÀöµÄ±ëÐÎ´óºº£¬Å¨Ã¼´óÑÛ£¬ÂúÁ³ºáÈâ£¬ºú×Ó¹ÎµÃ¸É¸É¾»¾»¡£\n");
        set("combat_exp", 5000000);
	set("attitude", "friendly");
	set("per",10);
	set("str", 50);
	set("force",5000);
	set("max_force",15000);
	set("force_factor",50);
	set_skill("dodge",200);
        set_skill("unarmed",150);
        set_skill("parry", 300);
       	set("lower_limit",20);
	set("too_late",0);
	set("first_dice",0);
        set("second_dice",0);
        set("third_dice",0);
    set("no_arrest",1);
	setup();
    carry_object("obj/armor/cloth")->wear();
}

void init()
{
        object ob;

        ::init();
        if( interactive(ob = this_player()) && !is_fighting() ) {
                remove_call_out("greeting");
                call_out("greeting", 1, ob);
        }
	add_action("do_bet", "bet");
	add_action("do_answer", "answer");	
}

void greeting(object ob)
{
	object gold;
	
    if( !ob || environment(ob) != environment() ) return;
	if(ob->query_temp("É½Á÷/Æ«Ìü")&&ob->query_temp("É½Á÷/killmonk")&&ob->query_temp("É½Á÷/killtaoist")
		&&ob->query_temp("É½Á÷/killxiucai"))
	{
		message_vision(HIY"$N¹þ¹þ´óÐ¦µÀ£º²»´í£¬²»´í£¬ÌìÉ±µÄÍºÂ¿Å£±Ç×ÓÇîËá£¬ËÀÁË¸É¾»¡£\n 
     $NÅÄÁËÅÄ$nµÄ¼ç°ò£¬ËµµÀ£º¸ÉµÃºÃ£¬ÕâÀïÊÇÄãµÄ±¨³ê¡£\n"NOR,this_object(),ob);
		gold=new("/obj/money/gold");
		gold->set_amount(ob->query_temp("É½Á÷/Æ«Ìü"));
		gold->move(ob);
		message_vision("$NË¬¿ìµØ¸ø$nÒ»Ð©½ð×Ó¡£\n",this_object(),ob);
		ob->delete_temp("É½Á÷/killmonk");
		ob->delete_temp("É½Á÷/killtaoist");		
		ob->delete_temp("É½Á÷/killxiucai");
		ob->delete_temp("É½Á÷/Æ«Ìü");
		return ;
	}else if (ob->query_temp("É½Á÷/Æ«Ìü"))
	{
		message_vision(HIY"$NÏò$n²»ÄÍ·³µÀ£ºÄúµ¹ÊÇ¿ìµã°¡£¬±ðÄ¥Ä¥²ä²äÁË¡£\n"NOR,this_object(),ob);
		message_vision("$n±»ÂîÂîßÖßÖµÄ$NÒ»½ÅÌß½øÆ«Ìü¡£\n",this_object(),ob);
		ob->move("/d/shanliu/dufang2");
		return;
	}
       switch( random(10) )
		{
                case 0:
                        say( "½ðºú×ÓÐ¦ßäßäµØËµµÀ£ºÕâÎ»" + RANK_D->query_respect(ob)
                                + "£¬¹ýÀ´¶ÄÁ½ÊÖ£¬¿ª¿ªÐÄ°É¡£\n");
                        break;
                case 1:
                        say( "½ðºú×Ó»ÎÁË»ÎÊÖÖÐµÄ÷»×Ó£¬½ÐµÀ£ºÕâÎ»" + RANK_D->query_respect(ob)
                                + "£¬Ð¡¶Ä¿ÉÒÔÑø¼Òºý¿Ú£¬´ó¶Ä¿ÉÒÔ¶¨¹ú°²°î¡£À´°É£¡\n");
                        break;
                case 2:
                        say( "½ðºú×ÓËµµÀ£ºÕâÎ»" + RANK_D->query_respect(ob)
                                + "£¬½øÀ´£¡½øÀ´£¡ ÊäÁËËãÎÒµÄ£¡\n");
                        break;
        }
		return;
}
 
string *dice = ({
"[31m
	¡Ñ 

[37m",
"	¡Ñ

	    ¡Ñ
",
"	¡Ñ
	  ¡Ñ 
	    ¡Ñ
",
"	[31m¡Ñ  ¡Ñ

	¡Ñ  ¡Ñ
[37m",
"	¡Ñ  ¡Ñ
	  ¡Ñ
	¡Ñ  ¡Ñ
",
"	¡Ñ ¡Ñ
	¡Ñ ¡Ñ
	¡Ñ ¡Ñ
"
		});

int do_answer(string arg)
{
	object me;
	
	me=this_player();
	if(!me->query_temp("jinhuzi_ask"))
		return 0;
	me->delete_temp("jinhuzi_ask");
	if(arg=="no")
	{
		message_vision("$N¶Ô$nµãµãÍ·µÀ£º¡°Èç´Ë¾Í²»¶à´òÈÅÁË¡£¡±\n",this_object(),me);
		me->delete_temp("É½Á÷/ºÀ¶Ä");
		return 1;
	}
	if(arg=="yes")
	{
		tell_object(me, 
HIR"½ðºú×Ó¶ÔÄãÇÄÉùËµµÀ£º´óÏÀÄúÏë±ØÒ²ÖªµÀ£¬ÔÛ¶Ä·»Àï×î¼É»äÊ²Ã´ºÍÉÐÄá¹ÃÁË£¬
ËùÎ½Ò»¼û¹âÍ·£¬·ê¶Ä±ØÊä£¬ÕâÑù²»°Ñ´óÒ¯ÃÇÈ«ÏÅÅÜÁË£¬´óÒ¯ÄúµÄÔËÆøÖ®ËùÒÔß¯
²î¡£¡£¡£ÔÚÆ«ÌüÀïÆ«¾ÍÓÐ¼¸¸öºÍÉÐµÀÊ¿£¬É·ÊÇÌÖÑá£¬Ö»ÒªÄã°ÑËûÃÇ¸Ï×ß¡£¡£»ò
Õß¸É´à³¬¶ÈÁËËûÄÌÄÌµÄ£¬¹þ¹þ£¬Ê²Ã´¶¼ºÃËµÀ²¡£\n"NOR);
		me->set_temp("É½Á÷/Æ«Ìü",me->query_temp("É½Á÷/ºÀ¶Ä"));
		me->delete_temp("É½Á÷/ºÀ¶Ä");
		call_out("move_player",2,me);
		return 1;
	}
	return 0;
}

int move_player(object me)
{
	if(environment(me)!=environment())
		return 1;
	message_vision(HIY"$N½«$nÁìµ½Æ«ÌüÃÅ¿Ú£¬´ò¿ªÃÅ£¬¶Ô$nËµ£º´óÏÀ£¬ÄúÇë¡£\n"NOR,this_object(),me);
	me->move("/d/shanliu/dufang2");
	return 1;
}


	
int do_bet(string arg)
{
    int i,bet_amt;
    int bet_type;
    object me, gold;
    string message;
	if(!arg || !sscanf(arg, "%d %d",bet_type,bet_amt))
                return notify_fail("bet <ÖÖÀà> <½ðÁ¿>\n");
	if(bet_type>18 || bet_type < 0)
		return notify_fail("ÖÖÀàÖ»¿É´ÓÁãµ½Ê®°Ë\n");
	me = this_player();
	if(me->is_busy())
		return notify_fail("ÄãÉÏ¸ö¶¯×÷»¹Ã»Íê³É¡£\n");
	gold = present("gold_money", me);
	if(!gold) return notify_fail("ÄãÉíÉÏÃ»ÓÐ½ð×Ó¡£\n");
	if((int) gold->query_amount() < bet_amt)
	return notify_fail("ÄãÉíÉÏÃ»ÓÐÄÇ÷á¶à½ð×Ó¡£\n");	
	if((int) this_object()->query("lower_limit") > bet_amt)
	return notify_fail("ÕâÕÅÌ¨µÄ×îÐ¡¶Ä×¢ÊÇ"+chinese_number((int) 	this_object()->query("lower_limit"))+"Á½½ð×Ó¡£\n");
        if((int) this_object()->query("too_late") )
        return notify_fail("ÕâÆÌÀ´²»¼°ÁË£¬µÈÏÂÊÖ°É£®\n");
	if((int) me->query("gamble/amount"))
	{ 
	if(bet_type != (int) me->query("gamble/type"))
	return notify_fail("Äã²»¿ÉÔÚÒ»ÆÌÖÐÏÂ²»Í¬µÄ×¢£®\n");
        gold->add_amount(-bet_amt);
        me->start_busy(1);
        if(bet_type == 0)
                message = sprintf(RED"Ð¡"NOR);
        if(bet_type == 1)
                message = sprintf(RED"´ó"NOR);
        if(bet_type == 2)
                message = sprintf(RED"Î§÷»"NOR);
        if(bet_type >=3)
                message = sprintf(RED"%s"NOR,chinese_number(bet_type));
       message_vision(sprintf("$NÓÖ´ÓÉíÉÏÄÃ³ö%sÁ½»Æ½ð£¬¼ÓÑ¹ÔÚ%sÉÏ£®\n",
                                chinese_number(bet_amt), message), me);
        bet_amt += (int) me->query("gamble/amount");
                me->set("gamble/amount",bet_amt);

	}
	else
	{
		gold->add_amount(-bet_amt);
		me->start_busy(1);
		if(bet_type == 0)	
			message = sprintf(RED"Ð¡"NOR);
		if(bet_type == 1)
			message = sprintf(RED"´ó"NOR);
			if(bet_type == 2)
					message = sprintf(RED"Î§÷»"NOR);
		if(bet_type >=3)
					message = sprintf(RED"%s"NOR,chinese_number(bet_type));
		message_vision(sprintf("$N´ÓÉíÉÏÄÃ³ö%sÁ½»Æ½ð£¬Ñ¹ÔÚ%sÉÏ£®\n",
					chinese_number(bet_amt), message), me);
		me->set("gamble/type",bet_type);
		me->set("gamble/amount",bet_amt);
	}
	stat[bet_type] += bet_amt;
	if( find_call_out("rolldice") == -1)
		call_out("rolldice",30);
	if( find_call_out("rolldice") >10 && find_call_out("advertise") == -1)
		call_out("advertise",random(5)+1);
	if((int) bet_amt >= 20&&bet_type<2)
		me->add_temp("É½Á÷/ºÀ¶Ä",bet_amt);
	return 1;
}
void advertise()
{
        switch( random(3) ) {
                case 0:
message_vision("$NÏòÄãÐ¦µÀ£º¿ìÏÂ×¢£¡Õâ×¢ÄãÒ»¶¨»áÓ®£¡\n",this_object());
                        break;
                case 1:
message_vision("$NËµµÀ£ºÔÙ²»ÏÂ×¢¾ÍÀ´²»¼°ÁË£¡\n",this_object());
                        break;
                case 2:
message_vision("$NÂúÃæºì¹â£¬ËÊÓÁ×Å´ó¼Ò£º¼Ó£¡ÔÙ¼Ó´óÄãµÄ¶Ä×¢£¡Ò»¶¨Ó®£¡\n",this_object());

                        break;
			}

        if( find_call_out("rolldice") >=10)
                call_out("advertise",random(4)+5);
return;
}

void rolldice()
{
	this_object()->set("too_late",1);
	message_vision("$N´óÉù½ÐµÀ£ºÏÂ¶¨×¢£¡Ëµ°Õ£¬½«ÊÖÖÐµÄÈýÁ£÷»×ÓÈöÏòÍëÀï£®\n",this_object());
	message_vision("\n£®£®£®ÈýÁ£÷»×ÓÔÚÍëÀï±ÄÌø×Å£¬·¢³öÔÃ¶úµÄÉùÒô£®£®£®\n",this_object());
	pre_cal();
	call_out("first_dice",3);
return;
}

void first_dice()
{
	int first;
        switch( random(3) ) {
                case 0:
        message_vision("\nÒ»Á£÷»×Óµ¯ÁË¼¸ÏÂ£¬Í£ÔÚ£º\n\n",this_object());
                        break;
                case 1:
        message_vision("\nÒ»Á£÷»×Ó£¢¶£¶£¶££¢µÄÌø¶¯ÁË¼¸ÏÂ£¬»º»ºµÄÍ£ÁËÏÂÀ´£º\n\n",this_object());
                        break;
                case 2:
        message_vision("\nÈýÁ£÷»×ÓÏà»¥Ò»×²£¬Ò»¿ÅÖ±ÂäÍëµ×£º\n\n",this_object());

                        break;
        }

	first = (int) this_object()->query("first_dice");
	message_vision(dice[first], this_object());
	this_object()->set("first_dice",first+1);
	call_out("second_dice",4);
return;
}

void second_dice()
{
	int second;
        switch( random(3) ) {
                case 0:
       message_vision("\nÓÖÒ»Á£÷»×Ó»º»ºµÄÍ£ÁËÏÂÀ´£º\n\n",this_object());
                        break;
                case 1:
        message_vision("\nµÚ¶þÁ£÷»×ÓÔÚÍë±ßÐý×ª²»Í££®£®ºöµØ·­ÁË¸öÉí£º\n\n",this_object());
                        break;
                case 2:
        message_vision("\n¶þÁ£÷»×ÓÏà»¥Ò»×²£¬ÆäÖÐÒ»¿ÅÌøÁËÒ»Ìø£º\n\n",this_object());

                        break;
        }
        second= (int) this_object()->query("second_dice");
        message_vision(dice[second], this_object());
        this_object()->set("second_dice",second+1);
	call_out("third_dice",5);


return;
}
void third_dice()
{
        int third;
        switch( random(3) ) {
                case 0:
       message_vision("\n×îºóÒ»Á£÷»×ÓÔÚÍëÀï»¬ÁËÁ½ÏÂ£¬ÖÕÓÚÍ£ÔÚ£º\n\n",this_object());
                        break;
                case 1:
        message_vision("\n»¹ÓÐ×îºóÒ»Á£÷»×ÓàÖåÞåÞµÄ×ª¸ö²»Í££®£®ÖÕÓÚ£º\n\n",this_object());
                        break;
                case 2:
        message_vision("\n×îºóÒ»Á£÷»×ÓÒ²ÖÕÓÚÍ£ÎÈÁË£º\n\n",this_object());

                        break;
        }
        third= (int) this_object()->query("third_dice");
        message_vision(dice[third], this_object());
        this_object()->set("third_dice",third+1);
        call_out("end_the_round",2);
return;
}

int event_begin(object me)
{
	//if (query("asking_person"))
		//return 1;
	message_vision(HIC"\n$NÍ¬ÇéµÄ¶Ô$nËµ£º¡°´óÏÀ½ñÌìÊÖ·çºÃÏñ²»Ì«Ë³Ñ½£¬ÊäµÃ¿ÉÕæ²»ÉÙ¡£
ÊÇ²»ÊÇÏë·­±¾°¡¡£ÕâÓÐ¼þºÃÊÂ£¬Ö»ÒªÄã×ö³ÉÁË£¬²»½ö°ÑÄãÅâµÄËÍ»¹£¬½ðºú×ÓÎÒ
»¹»áËÍÉÏ»Æ½ð°ÙÁ½.²»ÖªÄã¿Ï²»¿Ï×ö(answer yes or no)£¿\n"NOR,this_object(),me);
	//add_action("do_answer", "answer");	
	me->set_temp("jinhuzi_ask",1);
	return 1;
}


void end_the_round()
{
	int tot,reward,i,first, second, third;
	object *inv;
	first = (int) this_object()->query("first_dice");
        second= (int) this_object()->query("second_dice");
        third = (int) this_object()->query("third_dice");

// announce results:
message_vision(sprintf("\n$N¸ßÉù½ÐµÀ£º%s£¬%s£¬%s£¬",
		chinese_number(first),chinese_number(second),chinese_number(third)),
		this_object());
// see who is the winner!
if( second == first && third == first)
{
	message_vision("´óÐ¡Í¨³Ô£¡£¡\n",this_object());
	inv = all_inventory(environment(this_object()));
    for(i=0; i<sizeof(inv); i++) 
	{
		if( userp(inv[i]) && (int) inv[i]->query("gamble/amount") )
		{
			if((int) inv[i]->query("gamble/type") == 2)
			{
				message_vision("Ó®¼Ò£­$N£¬Ò»ÅâÈýÊ®Áù£¡£¡\n",inv[i]);
				if(inv[i]->query_temp("É½Á÷/ºÀ¶Ä"))
					inv[i]->delete_temp("É½Á÷/ºÀ¶Ä");
				reward = (int) inv[i]->query("gamble/amount") * 36 * 10000;
				// also increae his betting skill
				inv[i]->improve_skill("betting", reward/100);
				pay_him( inv[i],reward);
			}
			inv[i]->set("gamble/amount",0);
			//show msg for those who lose over 20 gold
			/*
            if(inv[i]->query_temp("É½Á÷/ºÀ¶Ä")>=20 && inv[i]->query_temp("É½Á÷/ºÀ¶Ä")<=60)
				message_vision(HIY"½ð´óºú×Ó¹Å¹ÖµØ¶Ô$NÐ¦ÁËÐ¦µÀ£ºÔÙÏÂÒ»×¢£¬Ëµ²»¶¨ÓÐÊ²Ã´ºÃÔËµÀßÏ¡£\n"NOR,inv[i]);
			else if (inv[i]->query_temp("É½Á÷/ºÀ¶Ä")>=60)
				event_begin(inv[i]);
			*/
		}		
	}
 }
else
{
	tot = first+second+third;
	message_vision(sprintf("%sµã£¬",chinese_number(tot)),this_object());
	if( tot>10 )
		message_vision("Åâ´ó³ÔÐ¡£¡\n",this_object());
	else
		message_vision("ÅâÐ¡³Ô´ó£¡\n",this_object());
	inv = all_inventory(environment(this_object()));
	for(i=0; i<sizeof(inv); i++) 
	{
		if( userp(inv[i]) && (int) inv[i]->query("gamble/amount") )
		{
			if((int) inv[i]->query("gamble/type") == tot)
			{
					message_vision("Ó®¼Ò£­$N£¬Ò»Åâ°Ë£¡\n",inv[i]);
			if(inv[i]->query_temp("É½Á÷/ºÀ¶Ä"))
				inv[i]->delete_temp("É½Á÷/ºÀ¶Ä");           
					reward = (int) inv[i]->query("gamble/amount") * 8 * 10000;
	// also increae his betting skill
					inv[i]->improve_skill("betting", reward/100 );
					pay_him( inv[i],reward);
					inv[i]->set("gamble/amount",0);
			}
			else if(((int) inv[i]->query("gamble/type") == 0 && tot <=10 ) ||
			((int) inv[i]->query("gamble/type") == 1 && tot > 10 ))
             {
                message_vision("Ó®¼Ò£­$N£¬Ò»ÅâÒ»£¡\n",inv[i]);
				if(inv[i]->query_temp("É½Á÷/ºÀ¶Ä"))
				inv[i]->delete_temp("É½Á÷/ºÀ¶Ä");                
                reward = (int) inv[i]->query("gamble/amount") * 2 * 10000;
				// also increae his betting skill
                inv[i]->improve_skill("betting", reward/100 / 2 * 1);
                pay_him( inv[i],reward);
                inv[i]->set("gamble/amount",0);
			}
			else
			{
			// here are the losers
				reward = (int) inv[i]->query("gamble/amount");
				inv[i]->decrease_skill("betting", reward, 1);
				if (inv[i]->query_temp("É½Á÷/ºÀ¶Ä")>=60)
				{
					//inv[i]->set("gamble/amount",0);
					event_begin(inv[i]);
				}else if (inv[i]->query_temp("É½Á÷/ºÀ¶Ä")>=20 && inv[i]->query("gamble/amount") >=20)
				{
					message_vision(HIY"½ð´óºú×Ó¹Å¹ÖµØ¶Ô$NÐ¦ÁËÐ¦µÀ£ºÔÙÏÂÒ»×¢£¬Ëµ²»¶¨ÓÐÊ²Ã´ºÃÔËµÀßÏ¡£\n"NOR,inv[i]);
				}
				inv[i]->set("gamble/amount",0);
			}
        }
	}
}
this_object()->set("too_late",0);
this_object()->set("first_dice",0);
this_object()->set("second_dice",0);
this_object()->set("third_dice",0);
clear_stat();
return;
}
void pay_him(object who, int amount)

{
        object ob;
        object cash, tencash, silver, gold, coin;

        if( amount < 1 ) amount = 1;
/*        if( amount/1000000 ) {
                ob = new(TECASH_OB);
                ob->set_amount(amount/1000000);
                ob->move(who);
                amount %= 1000000;
        }
        if( amount/100000 ) {
                ob = new(THCASH_OB);
                ob->set_amount(amount/100000);
                ob->move(who);
                amount %= 100000;
        }
*/    
        if( amount/10000 ) {
                ob = new(GOLD_OB);
                ob->set_amount(amount/10000);
		ob->set("name","´¿½ðÒ¶×Ó");
                ob->move(who);
                amount %= 10000;
        }
        if( amount/100 ) {
                ob = new(SILVER_OB);
                ob->set_amount(amount/100);
                ob->move(who);
                amount %= 100;
        }
        if( amount ) {
                ob = new(COIN_OB);
                ob->set_amount(amount);
                ob->move(who);
        }
}
int accept_object(object who, object ob)
{
	int bet_type;
	string message;
	
                if( ob->value() >= 100) {
                        say("½ðºú×ÓºÇºÇµÄÐ¦µÀ£ºÐ»ÉÍ...\n");
	message_vision("$NÔÚ$n¶ú±ßàÖ¹¾ÁË¼¸¾ä£®£®\n",this_object(),who);
	bet_type = random(19);
        if(bet_type == 0)
                message = sprintf(RED"Ð¡"NOR);
        if(bet_type == 1)
                message = sprintf(RED"´ó"NOR);
        if(bet_type == 2)
                message = sprintf(RED"Î§÷»"NOR);
        if(bet_type >=3)
                message = sprintf(RED"%s"NOR,chinese_number(bet_type));

	tell_object(who,"½ðºú×ÓÇÄÇÄ¸æËßÄã£ºÏÂÊÖ¶ùÑ¹"+message+"£¬Ò»¶¨Ó®£¡\n");
	message_vision("$N»áÐÄµÄÎ¢Ð¦ÆðÀ´£®£®\n",who);
	
                        return 1;
                } else {
                    say("½ðºú×ÓËµµÀ£ºÕâµãÇ®Äã»¹ÊÇ×Ô¼ºÓÃ°É£¡\n");
                        return 0;
                }
        return 0;
}

void clear_stat()
{
	int i;
	for(i=0;i<=18;i++)
		stat[i]=0;
}

void pre_cal()
{
        int index = 12;
        int amount ;
        int amt1,amt2,amt3;
        int i;
	string temp="";
        stat[2] *= 36;
// this is where we see what to come out to win for the casino!
// there never is a fair bet *grin
        for(i=3;i<=10;i++)
                stat[i] = 8*stat[i] + stat[0];
        for(i=11;i<=18;i++)
                stat[i] = 8*stat[i] + stat[1];
        stat[3] += stat[2];
        stat[18] += stat[2];
        amount = stat[12];
// debug
        for(i=0;i<=18;i++)
	temp += sprintf("%d:%d,",i,stat[i]);
	temp += "\n";
// now we have in this arry stat[] the amount of money we have to pay i
// have to pay
        for(i=2;i<=18;i++)
        if(stat[i] < amount) amount = stat[i];
	temp +=sprintf("%d\n",amount);
	low_index = ({});
        for(i=2;i<=18;i++)
        if(stat[i] <= amount) low_index += ({ i });
	for(i=0;i<sizeof(low_index);i++)
	temp += sprintf("%d,",low_index[i]);
	temp += "\n";

        index = low_index[random(sizeof(low_index))];
	temp += sprintf("%d\n",index);
//	message_vision(temp+"\n",this_object());
// now we have index points to the winning number and amount points to the highest!!
// lets decide cheat or not
this_object()->set("first_dice",0);
this_object()->set("second_dice",0);
this_object()->set("third_dice",0);
	if( !random(3) ) {
		if( index == 2  )
		{
		amount = random(6);
		this_object()->set("first_dice",amount);
                this_object()->set("second_dice",amount);
                this_object()->set("third_dice",amount);
		}
		else 
		if( index == 3)
		{
                amount = 0; 
                this_object()->set("first_dice",amount);
                this_object()->set("second_dice",amount);
                this_object()->set("third_dice",amount);
                }
		else
		if( index == 18 )
		{
                amount = 5;
                this_object()->set("first_dice",amount);
                this_object()->set("second_dice",amount);
                this_object()->set("third_dice",amount);
		}
		else
		{
		if( index / 3 * 3 == index ) amount = index / 3 + 1;
		else
		amount = index / 3;
		this_object()->set("first_dice",amount-1);
		index -= amount;
		amount = index / 2;
		this_object()->set("second_dice",amount-1);
		index -= amount;
		amount = index /1;
		this_object()->set("third_dice",amount-1);
		}

	}
	else
	{
this_object()->set("first_dice",random(6));
this_object()->set("second_dice",random(6));
this_object()->set("third_dice",random(6));
	}

}

