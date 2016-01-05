inherit NPC;
#include <ansi.h>
inherit F_MASTER;

int s_quest();
int give_reward(object who,mapping quest);
int time_period(int timep, object me);
int wait_period(int timep, object me);
int newbie_quest();
string sysmsg;

void create() {

    set_name(HIY"Ìì»úÀÏÈË"NOR, ({ "tian ji","tianji"}) );
    set("gender", "ÄĞĞÔ");
    set("long", "
Ìì»úÀÏÈËÄê¹ıÁù¼×£¬º×·¢Í¯ÑÕ¡£ÔÚ±øÆ÷Æ×ÉÏÅÅÃûµÚÒ»£¬ÓÈÔÚÉÏ¹Ù£¬Ğ¡Àî
Ö®ÉÏ£®´ËÈËÒàÕıÒàĞ°£¬·²ÊÂ¶¼ÓÉ°®¶ñ¶ø¶¨¡£¡£¡£¡£\n");
	set("attitude", "peaceful");
	create_family("äìÒ£ÅÉ", 1, "×æÊ¦");
	set("title", "ÏĞÔÆÒ°º×");
	set("class","tianji");
	
	set("age", 99);
	set("str", 2600);
	set("NO_KILL",1);
	
	set("inquiry",	([
		"»ã±¨":		(: s_quest() :),
		"»Ø±¨":		(: s_quest() :),
	]));
		
	set("chat_chance", 1);
	set("chat_msg", ({ 
		"Ìì»úÀÏÈËÄÃÆğºµÑÌ³éÁË¼¸¿Ú¡£¡£¡£¡£\n"
	}));
	
	set("combat_exp", 20000000);
	set("score", 200000);
	
	set_skill("unarmed", 200);
	set_skill("force", 200);
	set_skill("iron-cloth", 200);
	set_skill("yiqiforce", 300);
	set_skill("dagger",200);
	
	map_skill("iron-cloth", "yiqiforce");
	map_skill("force", "yiqiforce");
	map_skill("unarmed", "yiqiforce");
	
	
	setup();
	carry_object(__DIR__"obj/jade-cloth")->wear();
	carry_object(__DIR__"obj/hanyan")->wield();
}

int s_quest(){
	object me = this_player();
	object ob = this_object();
	
	if (me->is_fighting())	return notify_fail("ÄãÏÖÔÚÕıÃ¦¡£\n");
		
	if (me->query("quest/quest") == "³ÁİàÂäÏã"){
		if (time() - me->query("quest_time") > 290) {
			tell_object(me,"Ìì»úÀÏÈË²»ÂúµØËµ£ºÄãÕâ¸öÀÁ¹ÇÍ·£¬·¢´ôÊ±¼äÌ«³¤ÀÖ¡£\n");
			tell_object(me,"ÄãÃ»ÓĞÔÚ¹æ¶¨µÄÊ±¼äÄÚÍê³ÉÌì»úÀÏÈËµÄÈÎÎñ£¬ÄãµÄÈÎÎñ×Ô¶¯È¡ÏûÁË¡£\n");
			me->delete("quest");				// both are required
			me->delete("annie_quest");
			me ->delete_temp("annie_quest");		
			me->delete_temp("quest_number");
			me->delete("cont_quest");
			me->delete_temp("luyu");
			return 1;
		}
		if (time()-me->query("quest_time")< 180) {
			tell_object(me,"Ìì»úÀÏÈËËµ£ººÈ²è¸üÒÂÉìÀÁÑü£¬»òÕß¡£¡£¡£¡£\n");
			message_vision("Ìì»úÀÏÈËÒ»»ÓÊÖ£¬$NÌÚÔÆ¼İÎíµØ·ÉÁË³öÈ¥¡£\n"NOR, me);
			if (me->query("gender")=="ÄĞĞÔ")
				me->move("/d/qianjin/hotel2");
			else
				me->move("/d/fugui/kefang");
			tell_object(me,"£¨Äã»¹ĞèÒª"+ chinese_number(me->query("quest_time")+180-time())+
				"ÃëÖÓ²ÅÄÜÍê³ÉÕâ¸öÈÎÎñ£©\n");
			return 1;
		}
		tell_object(me,"Ìì»úÀÏÈËËµ£º²»´í²»´í£¬ÀÍÒİ½áºÏ£¬²ÅÄÜ¹»³¤ÊÙ¹ş¡£\n");
		if ( QUESTS_D->verify_quest(me,"³ÁİàÂäÏã"))
			QUESTS_D->special_reward(me,"³ÁİàÂäÏã");
		return 1;
	}
	
	command("dapp " + me->query("id"));
	return 1;
}


int accept_fight(object me) {
	command("say ÉúÃü¿É¹ó£¡²»Òª×ÔÑ°ËÀÂ·£¡");
	return 0;
}


void init() {
	add_action("give_quest", "quest");
	add_action("q_return", "qreturn");
}


int accept_object(object who, object ob) {
	if (QUESTS_D->accept_quest_object(who, ob, this_object()))	{
		return 1;	
	}
	else
	{	
			tell_object(who, "Ìì»úÀÏÈËĞ¦ÎûÎûµØËµ£ºÏëĞ¢¾´Ò¯Ò¯¾Í¶à¸øÒ¯Ò¯¸É»î£¡\n");
			return 0;
	}
}

int q_return(string arg){
	object me,box;
	mapping quest,items;
	string name,*dir;
	int num, index, i;
	
	me = this_player();

	if (!(box = present("treasure box", me)))
		return notify_fail("´ËÃüÁîÖ»ÓĞĞ¯´øĞşÁéÓñºĞµÄÈË²ÅÄÜÊ¹ÓÃ¡£\n");
	
	if (!box->query("quest_box"))
		return notify_fail("´ËÃüÁîÖ»ÓĞĞ¯´øĞşÁéÓñºĞµÄÈË²ÅÄÜÊ¹ÓÃ¡£\n");
	
//	items = box->item_list();
	
	items = me->query_qitems();
	
	if (!items || sizeof(items)<1)
		return notify_fail("ÄãµÄĞşÁéÓñºĞÊÇ¿ÕµÄ¡£\n");
	
	if (arg)
		name = arg;
	else if (mapp(quest = me->query("quest")))
		name = quest["quest"];
	else
		return notify_fail("ÄãÏë½»»¹ÄÄÒ»¸ö£Ñ£õ£å£ó£ôÎïÆ·£¿\n");
	
	if (!name)
		return notify_fail("ÄãÏë½»»¹ÄÄÒ»¸ö£Ñ£õ£å£ó£ôÎïÆ·£¿\n");
		
	if (box->query("timer/op") + 2> time()) {
		write("Îª½ÚÊ¡ÏµÍ³×ÊÔ´£¬ĞşÁéÓñºĞÃüÁî²»ÄÜÁ¬Ğø²Ù×÷£¬ÇëµÈ´ı£²ÃëÖÓ¡£\n");
		return 1;
	}
	box->set("timer/op", time());
	
	arg = box->replace_color(name);
	num = sizeof(items);
	dir = keys(items);
	index = member_array(arg, dir);
	if (index == -1) {		// ×öÒ»´ÎÎŞÑÕÉ«µÄÆ¥Åä
		for (i= 0; i<num; i++) {
			if ( arg == "/feature/nada"->ngstr(dir[i])) {
				index = i;
				break;
			}
		}
	}

	if (index==-1)
		return notify_fail("ÄãµÄĞşÁéÓñºĞÖĞÃ»ÓĞ"+arg+"Õâ¸öÎïÆ·¡£
£¼¸ñÊ½£º£ñ£ò£å£ô£õ£ò£î¡¡ÖĞÎÄÎïÆ·Ãû£¾\n");

	if (QUESTS_D->accept_quest_object(me, dir[index], this_object())){	
		box->do_qqdiscard(dir[index],me,0);
		return 1;							
	}
	tell_object(me, "Ìì»úÀÏÈËËµ£ºÕâ¸ö¶«Î÷²»ÊÇÎÒÏëÒªµÄ¡£\n");
	return 1;	
}

int give_quest(string arg) {
	
	int gold,rt,gr, level;
	object who;
	
	who = this_player();
//	ÕâÀïÊÇ¸ø¸Õ½øÀ´µÄ£î£å£÷£â£é£åµÄ£æ£é£ø£å£ä¡¡£ñ£õ£å£ó£ô¡£	
	if (REWARD_D->riddle_check(this_player(),"ĞÂÊÖÈëÃÅ") 
		&& !REWARD_D->check_m_success(this_player(),"ĞÂÊÖÈëÃÅ")) {
		newbie_quest();
		return 1;
	}
	
	gold  = this_player()->query("deposit")/100;
	if ((arg == "cancel" || arg == "fail") && this_player()->query("quest"))
	{
			
		// ²»ÄÜÈ¡ÏûÀà£º
		rt = this_player()->query("quest")["cancel"];
		if (rt == -1)
		{
			tell_object(this_player(),"ÕâÃ´ÖØÒªµÄÈÎÎñ£¬ÔõÃ´ÄÜÈ¡ÏûÄØ£®£®£®\n");
			return 1;
		}
		
		level = F_LEVEL->get_level( who->query("combat_exp"));
		
		if (level >= 80)		gr = 200;		// 4M
		else if (level >=50)	gr = 150;		// 2M
		else if (level >=30) 	gr = 100;		// 1M
		else if (level >=10)	gr = 50;		
		else 					gr = 25;
		
		if (arg == "cancel")		gr = gr*2;

/*		if (rt>0)
			gr = gr + gr*rt/100;	*/
			
		// this is for quest optimization
		if (who->query("timer/quest_cancel") + 300 > time())
		{
			who->add("marks/quest_cancel",1);
		}
		who->set("timer/quest_cancel",time());
        
        if (gold <gr)
		{
			tell_object(this_player(),"ÄãÒøĞĞÀï´æ¿î²»¹»"+chinese_number(gr)+"Á½Òø×Ó¡£\n");
			return 1;
		}
        
        who->add("deposit", -gr*100);
        
        if ( arg == "cancel")
        {
        	tell_object(who, YEL"Ìì»úÀÏÈËµàÁËµàÊÖÀïµÄ"+chinese_number(gr)+"Á½Òø×ÓÀÖºÇºÇµØËµ£º¼ÈÈ»²»Ïë×öÕâ¸ö¾Í»»Ò»¸ö°É¡£
£¨ÄãÏÖÔÚÕËÃæÉÏ»¹ÓĞ"+chinese_number(gold-gr)+"Á½Òø×Ó£©\n"NOR);
		}	
		else
		{
			//µÈÁËĞ¡ÓÚ12·ÖÖÓ£¬quest failÒÔºó»¹ÒªµÈ3·ÖÖÓ²ÅÄÜÒªÈÎÎñ 
			if (time() - who->query("quest_time") < 720){
				who->set("next_time", time() + 180);
				tell_object(who, YEL"Ìì»úÀÏÈËÖå×ÅÃ¼Í·Ëµ£ºÎÒÒ²²»Ç¿ÈËËùÄÑ£¬¿ÛÄã"
				+ chinese_number(gr) +"Á½¶§Òø£¬È¥ĞİÏ¢ĞİÏ¢ÔÙÀ´ÁìĞÂÈÎÎñ°É¡£
				£¨ÄãÏÖÔÚÕËÃæÉÏ»¹ÓĞ"+chinese_number(gold-gr)+"Á½Òø×Ó£©\n"NOR);
			} else 
			//µÈÁË´óÓÚ12·ÖÖÓ£¬quest failÒ²Ö±½ÓÈ¡Ïû£¬²»ĞèÒªÔÙµÈ3·ÖÖÓ
				tell_object(who, YEL"Ìì»úÀÏÈËÖå×ÅÃ¼Í·Ëµ£ºÕâµãÊÂ¶¼°ì²»ºÃ£¬²»¹ı¿´ÔÚÄãµÈÁËÕâÃ´¾Ã£¬
ÓÖĞ¢¾´ÎÒ" + chinese_number(gr) +"Á½Òø×ÓµÄ·İÉÏ£¬¸øÄã»»¸öÈÎÎñ°É¡£
£¨ÄãÏÖÔÚÕËÃæÉÏ»¹ÓĞ"+chinese_number(gold-gr)+"Á½Òø×Ó£©\n"NOR);
		}		
		who->delete("quest");				// both are required
		who->delete("annie_quest");	
		who->delete_temp("annie_quest");	
		who->delete_temp("luyu");
		who->delete_temp("quest_number");
		who->delete("cont_quest");
		return 1;
	}
	
	return QUESTS_D->give_quest(this_player(), 
			([	"name" : this_object()->name(),
                                "employer" : "Ìì»úÀÏÈË" ])
			);	
}


void attempt_apprentice(object me) {
	switch(random(4)) {
		case 0:
			message_vision("$N¶Ô$nĞ¦ÎÊµÀ£ºÊ²Ã´ÊÇ¡ºĞÄ½£¡»£¿\n", this_object(),me);
			break;
		case 1:
			message_vision("$N¶Ô$nĞ¦ÎÊµÀ£ºÊ²Ã´ÊÇ¡ºµĞ²»¶¯£¬ÎÒ²»¶¯£»µĞÒ»¶¯£¬ÎÒÏÈ¶¯£¿¡»\n", this_object(),me);	
			break;
		case 2:
			message_vision("$N¶Ô$nĞ¦ÎÊµÀ£º¡ºÓĞĞÎ£¬ÎŞĞÎ¡»ÊÇÊ²Ã´£¿\n", this_object(),me);		
			break;
		case 3:
			message_vision("$N¶Ô$nĞ¦ÎÊµÀ£ºÎäÑ§µÄ×î¸ß¾³½çÊÇÊ²Ã´£¿\n", this_object(),me);
			break;
	}
}

int attack()
{
	object opponent;
	opponent = select_opponent();
	if (userp(opponent)) {
		if (random(10)) {
			set_temp("last_opponent", opponent);
			command("say ÉúÃü¿É¹ó£¬²»Òª×ÔÑ°ËÀÂ·¡£");
			this_object()->remove_all_killer();
			return 1;
		} else {
			command("say ²»ÖªËÀ»îµÄ¶«Î÷£¬È¥ËÀ°É¡£");
			COMBAT_D->do_attack(this_object(), opponent, query_temp("weapon"));
			return 1;
		}
	} else if(objectp(opponent)) {
		COMBAT_D->fight(this_object(), opponent);
		return 1;
	} else
		return 0;
	
}

void unconcious()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
        return ;

}

void die()
{
        int gin,kee,sen;
        gin =(int)query("max_gin");
        kee =(int)query("max_kee");
        sen =(int)query("max_sen");
        set("eff_kee",kee);set("kee",kee);
        set("eff_gin",gin);set("gin",gin);
        set("eff_sen",sen);set("sen",sen);
        return ;

}

///	newbie µ¼ÓÎ£ñ£õ£å£ó£ô¡¡£æ£ï£ò¡¡£´£®£±¡£

int newbie_quest() {

	object me,ob,silver;
	
	me=this_player();
	ob=this_object();
	
	switch (me->query_temp("marks/newbie_quest")){
		case 1: tell_object(me,WHT"
Ìì»úÀÏÈËËµ£º¡°ÄãÈ¥°İ¼û¹ıÊ¯ÑãÁËÃ´£¿³ö·çÔÆ¶«³ÇÃÅµ½³à·åÂ·£¬ÏòÄÏ¾ÍÊÇÎäµ±É½¡£¡±\n\n"NOR);
			return 1;
		case 2: if (me->query_skill("literate",1) < 1) {
				tell_object(me,WHT"
Ìì»úÀÏÈËËµ£º¡°ÒªÑ§Îä´ó×Ö²»Ê¶ÔõÃ´ĞĞ£¿µ½±±³Ç¼°µÚ½Ö¹±ÔºÍõÈÊµÂÄÇ¶ùÈ¥
Ñ§µãÔÙÀ´ÕÒÎÒ°É£¨learn literate from kao guan with 1£©\n"NOR);
			return 1;
			}  		
			break;
		case 3: tell_object(me,WHT"
Ìì»úÀÏÈËËµ£º¡°ÄãÈ¥°İ¼û¹ıËş×£ÁËÃ´£¿ËûÔÚ¹ØÍâµÄ´óÕÑËÂ¡£¡±\n\n"NOR); 
			return 1;
		default:
	}

	if (REWARD_D->riddle_check(me,"ĞÂÊÖÈëÃÅ")==4)
	{
		tell_object(me,WHT"
Ìì»úÀÏÈËËµ£º¾ÛÉ³³ÉËş£¬»ıÒ¸³ÉôÃ£¬¹¦·ò¾ÍÊÇÕâÃ´Ò»µãµãÁ·³ÉµÄ¡£¹ØÍâ×ß
Ò»ÌË£¬ÄãÓ¦¸ÃÃ÷°×ÊìÏ¤µØÍ¼ÊÇ·Ç³£ÖØÒªµÄ£¬ËùÒÔÔÚÁ·¹¦Ö®Óà£¬Òª×ö¸öÓĞĞÄ
ÈË£¬¶à¿´¿´£¬¶à×ß×ß£¬¾ßÌåµÄµØÍ¼¿ÉÒÔ"HIR"£è£å£ì£ğ¡¡£í£á£ğ£ó"NOR+WHT"

·çÔÆÀïÒªÑ§µÄ¶«Î÷Ì«¶àÁË£¬Ò»Ê±°ë»á¶ùÎÒÒ²ºÜÄÑËµµÃÃæÃæ¾ãµ½£¬ºÃÔÚÕâĞ©
ÔÚ£è£å£ì£ğÎÄ¼şÀï¶¼ÓĞÏêÏ¸ËµÃ÷¡£

Ìì»úÀÏÈËÅÄÅÄÄãµÄÍ·Ëµ£º·çÔÆÀïµÄÊ¦¸µºÜ¶à£¬¸ö¸ö¶¼ÓĞ×Ô¼ºµÄ¿´¼Ò¹¦·ò£¬
È¥ÕÒÒ»¸öÊÊºÏÄãµÄ°É¡£Èç¹ûÒ»Ê±»¹²»Ïë°İÊ¦£¬¶«³Ç½ğÊ¨ïÚ¾ÖµÄ²éÃÍÊÇ¸öºÜ
²»´íµÄÈË£¬Ö»ÒªÌæËû"HIG"³öÁ¦"NOR+WHT"£¬Ëû¾Í»áÈÃÄãÑ§µã¹¦·ò£¬ËûÄÇÁ½ÏÂ×Ó£¬¶ÔĞÂÊÖÊÇ
ºÜÓĞ°ïÖúµÄ£¬¶øÇÒÒ²²»·ÑÊ²Ã´Á¦Æø¾ÍÄÜÑ§¡£

¶«³ÇµÄÕò·ç±øÆ÷ÆÌ¿ÉÒÔÂòĞ©±øÆ÷¡£
ÄÏ³Ç·çÔÆ²¼ÆÌÀïÀÏ²Ã·ìÄÇ¶ùÓĞĞ©ÆæÆæ¹Ö¹ÖµÄºÃÒÂ·ş¡£
Î÷³ÇµÄÇ§Òøµ±ÆÌºÍÄÏ¹¬Ç®×¯ÊÇÂòÂô¶«Î÷ºÍ´æÇ®µÄµØ·½¡£
±±³Ç¶ÁÇ§ÀïµÄ¾¯ÊÀÊé¾Ö×¨ÃÅ³öÊÛ¸øĞÂÊÖµÄÎä¹¦ÈëÃÅÊé¼®¡£
Èç¹ûÊÜÉËÁË¿ÉÒÔµ½Ç§½ğÂ¥×óÓÒÁ½²àµÄÔèÌÃ×ÓÀïÈ¥Ï´Ôè£¬¶àÏ´Ï´¾Í¿ÉÒÔ»Ö¸´¡£

ÔÚÎÒÕâ¶ù¿ÉÒÔ¼ÌĞøÁìÈÎÎñ£¨Quest£©£¬Èç¹ûÊµÔÚÍê²»³ÉÒ²Ã»¹ØÏµ£¬¿ÉÒÔ·ÅÆú
£¨Quest fail£¬µÈ´ı3·ÖÖÓ£©»òÕßÈ¡ÏûÈÎÎñ£¨Quest cancel£¬ÎŞĞèµÈ´ı£©£¬
µ±È»£¬ÎÒÒ²»á´ÓÄãÕË»§ÉÏ¿ÛµãÊÖĞø·Ñ¡£

Èç¹ûÓĞµÄ£ñ£õ£å£ó£ô²»ÖªµÀÔõÃ´Íê³É£¬¿ÉÒÔÊäÈë£è£å£ì£ğ¡¡£ñ£õ£å£ó£ôÃü
Áî£¬¶øºóÑ¡ÔñÏàÓ¦µÄµØÇø£¬ÀïÃæÓĞÏêÏ¸µÄ½éÉÜ£¬»òÕß¿ÉÒÔÔÚ£ã£è£á£ôºÍ
£î£å£÷ÆµµÀÉÏÑ¯ÎÊ£¬·çÔÆÀïµÄÈÈĞÄÈË»¹ÊÇºÜ¶àµÄ¡£

Òª×ö£ñ£õ£å£ó£ô£¬¼ÇµÃµ½Î÷³ÇğĞğÄ¸óÈ¥ÁìÒ»¸ö"HIR"ĞşÁéÓñºĞ"NOR+WHT"£¬Õâ¸ö¿ÉÊÇ·çÔÆµÄ
Ò»±¦°¡£¬µ½ÄÇ¶ù¿´¿´Äã¾ÍÖªµÀÊÇÊ²Ã´ÁË¡££¨´Ó¹ã³¡¡¡w w n ±ãµ½ÁË£©

ÕâÀïÊÇÒ»Á½Òø×Ó£¬ÄãÄÃ×ÅÉÏÂ·°É¡£Ê¦¸µÁì½øÃÅ£¬ĞŞĞĞÔÚ×ÔÉí£¡ÔÚ½­ºşÉÏÒª
¹ã½»ÅóÓÑ£¬³ı¶ñÑïÉÆ¡£ÒÔÄãµÄ×ÊÖÊ£¬ÈÕºó±Ø³É´óÆ÷£¡

"NOR);
		silver = new("/obj/money/coin_lock");
		silver->set_amount(1);	
		if (!silver->move(me))
			destruct(silver);
		
		REWARD_D->riddle_done(me,"ĞÂÊÖÈëÃÅ",200,1);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"ĞÂÊÖÈëÃÅ")==3)
	{	
		tell_object(me,WHT"
Ìì»úÀÏÈËÓÖËµ£º¡°ÏÖÔÚÄãÈ¥°İ¼ûÒ»ÏÂ¹ØÍâ´óÕÑËÂ±¦ËşµÄËş×££¬±ğ¿´Ëû²»ÊÇ
Ê²Ã´ÎäÁÖÃûÈË£¬Õâ¶ùµÄ¸ßÊÖÃÇÃ¿¸ö¶¼µ½ËûÄÇ¶ùÈ¥ºÈ¹ı²è¡£¡£¡£¡£
µ½¹ØÍâ¿ÉÒÔ´Ó³ÁÏãÕò×ß£¬»òÕßµ½Î÷³Ç·çÔÆæäÕ¾Íõ·ï´¦×âÂí³µ´©Ô½É³Ä®£¬³µ
·ÑÎÒÒÑ¾­ÌæÄã¸¶ÁË¡£¡±\n"NOR);
		me->set_temp("marks/wangfeng",1);
		me->set_temp("marks/newbie_quest",3);
		return 1;
	}

	if (REWARD_D->riddle_check(me,"ĞÂÊÖÈëÃÅ")==2)
	{		
		tell_object(me,WHT"
Ìì»úÀÏÈËÅÄÁËÅÄÄãµÄÍ·Ëµ£º¡°ºÃ£¡ºÃ£¡¹ÔËï¶ù£¬¶à¶à¸øÎÒÀÏÈË¼Ò¸É»î¶ù¾Í
ÄÜÌá¸ß½­ºşÀúÁ·£¬Ê¦¸µ²Å»á½ÌÄã¹¦·ò¡£²»¹ı£¬ÒªÑ§Îä¹¦²»Ê¶×Ö¿É²»ĞĞ¡£¡£¡£¡£\n"NOR);
		if (me->query_skill("literate",1)>=1) {
			tell_object(me,WHT"\nÄãÑ§µ½ÁË¶ÁÊéÊ¶×Ö£¬ÄãµÄ½­ºşÀúÁ··á¸»ÁË£¡\n"NOR);
			me->add("combat_exp",500);
			tell_object(me,YEL"
àÅ£¬¿´À´Èı×Ö¾­ÄãÒÑ¾­ÓĞµãĞÄµÃÁË£¬¼°µÚ½Ö¶ÁÇ§ÀïÄÇ¶ù»¹ÓĞĞí¶à´ò»ù´¡µÄ
Êé¼®£¬ÓĞ¿Õ¿ÉÒÔÈ¥×êÑĞÒ»ÏÂ¡£¼Ç×¡£¬Êé¶ÁµÃÔ½¶à£¬ÈË¾ÍÔ½´ÏÃ÷£¬Ñ§Îä¹¦£¬
¶ÁÃØ¼®¾ÍÄÜÊÂ°ë¹¦±¶¡££¨Ê¹ÓÃÃüÁîskills¿ÉÒÔ²é¿´Äã×Ô¼ºÑ§¹ıµÄ¼¼ÄÜ£©

Ìì»úÀÏÈËÓÖËµ£º¡°ÏÖÔÚÄãÈ¥°İ¼ûÒ»ÏÂ¹ØÍâ´óÕÑËÂ±¦ËşµÄËş×££¬±ğ¿´Ëû²»ÊÇ
Ê²Ã´ÎäÁÖÃûÈË£¬Õâ¶ùµÄ¸ßÊÖÃÇÃ¿¸ö¶¼µ½ËûÄÇ¶ùÈ¥ºÈ¹ı²è£®£®£®
µ½¹ØÍâ¿ÉÒÔ×Ô´ËÏòÄÏ´Ó³ÁÏãÕò×ß£¬»òÕßµ½Î÷³Ç·çÔÆæäÕ¾Íõ·ç´¦×âÂí³µ´©Ô½
É³Ä®£¬³µ·ÑÎÒÒÑ¾­ÌæÄã¸¶ÁË¡£¡±
£¨·çÔÆµÄµØ·½ºÜ´ó£¬Èç¹ûÄãÊÇĞÂÀ´Õ§µ½£¬¼ÇµÃËæÊ±Ê¹ÓÃ£í£á£ğÖ¸Áî£¬Í¬Ê±
Ò²¿ÉÒÔ²Î¿´help newbieÖĞµÄ·çÔÆµØÇøÆªÀ´µÃµ½Ò»Ğ©ÌáÊ¾¡££©\n"NOR);
			me->set_temp("marks/wangfeng",1);
			REWARD_D->riddle_set(me,"ĞÂÊÖÈëÃÅ",3);
			me->set_temp("marks/newbie_quest",3);
			return 1;
		} else {
			tell_object(me,WHT"
±±³Ç¹±ÔºÀïµÄ¿¼¹ÙÍõÈÊµÂÕıÔÚ´«ÊÚÈı×Ö¾­£¬ÄãÈ¥Ñ§Ò»µã¶ùÔÙ»ØÀ´¼ûÎÒ£º
learn literate from kao guan with 1\n\n"NOR);
			me->set_temp("marks/newbie_quest",2);
			return 1;
		}
	}

	
	if (REWARD_D->riddle_check(me,"ĞÂÊÖÈëÃÅ")==1)
	{
		tell_object(me,WHT"
Ìì»úÀÏÈËºÍÉÆµØ¿´×ÅÄãËµ£º¡°ÊÇµÚÒ»´Îµ½·çÔÆ³Ç°É£¬Ğ¡Ğ¡Äê¼Í¾ÍÄÜ³öÀ´´³
µ´½­ºşÁË£¬ÓĞÖ¾Æø£¡Õâ·çÔÆËµÄÑÒ²²»ÄÑ£¬Äã±ğ¿´ÏÖÔÚÄÇĞ©ÀÏ¼Ò»ïÃÇÅ£Æøºæ
ºæ£¬Ë×»°Ëµ³¤½­ºóÀËÍÆÇ°ÀË£¬Ç°ÀËËÀÔÚÉ³Ì²ÉÏ£¬Ö»ÒªÄã¿ÏÏÂ¿à¹¦£¬ÓĞ³¯Ò»
ÈÕ¿³ËûÃÇ¾ÍÏñ¿³¹ÏÇĞ²ËÒ»Ñù£®£®£®£®¡±

Ìì»úÀÏÈËËµ£º¡°·òÌì½«½µ´óÈÎÓÚË¹ÈËÒ²£¬±ØÏÈ¿àÆä½î¹Ç£¬ÀÍÆäĞÄÖ¾£¬²»¹ı£¬
ÍòÊÂ¿ªÍ·ÄÑ£¬Ïë³ÉÎª¸ßÊÖ£¬¾ÍÒª´ÓĞ¡ÊÂ×öÆğ ---- Ò²¾ÍÊÇ¸øÎÒÀÏÈË¼ÒÅÜÅÜ
ÍÈ¶ù¡£ÕâÑù°É£¬ÎÒºÃ¾ÃÃ»¼ûµ½Îäµ±Ê¯ÑãÕæÈËÁË£¬ÌæÎÒÈ¥ÏòËûÎÊ¸öºÃ¡£³ö·ç
ÔÆ¶«³ÇÃÅµ½³à·åÂ·ÏòÄÏ£¬ÉÏÁËÎäµ±É½¾ÍÄÜÕÒµ½Ëû¡£¡±\n\n"NOR);
		me->set_temp("marks/newbie_quest",1);
		return 1;
	}
	return 1;
}


void reset(){
	if (environment())
		command("chat [1;31m·çÆğÔÆÓ¿£¬ÌìµØ±äÉ«£¬ÍòÎï¸´ËÕ£¬Ó¢ĞÛ±²³ö¡£[0;32m");
}
