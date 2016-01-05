inherit NPC;
#include <ansi.h>

int nec_book();

void create()
{
        set_name("���羰�ĵ���", ({ "wandering taoist", "taoist" }) );
        set("gender", "Ů��");
        set("age", 32);
        set("long","һ���пɶ��ĵ��ã���һ���ɫ�ĵ��ۣ��������յ��ں��Ͽ��羰��\n");
        set("combat_exp", 21000);
        set("score", 200);
        set("class", "taoist");
        
        set("mana", 300);
        set("max_mana", 300);
        set("mana_factor", 5);

        set("inquiry", ([
                "�����": "�ڹ����ƾ��ˣ�����ɢɢ�ģ�������Ǹ��õط�����\n",
                "�ڼ�": (: nec_book :),
                "�������": (: nec_book :),
        ]) );

		
		set("chat_chance_combat", 80);
        set("chat_msg_combat", ({
                (: cast_spell, "netherbolt" :),
                (: cast_spell, "invocation" :),
        }) );

        set_skill("magic", 20);
        set_skill("move", 20);
        set_skill("force", 20);
        set_skill("spells", 30);
        set_skill("unarmed", 40);
        set_skill("sword", 40);
        set_skill("parry", 50);
        set_skill("dodge", 30);
        set_skill("gouyee", 50);
        set_skill("taoism", 30);
        set_skill("necromancy", 30); 
        set_skill("snowshade-sword",30);
        set_skill("notracesnow",30);

		set("no_arrest",1);
        
        map_skill("dodge","notracesnow");   
	map_skill("force", "gouyee");
        map_skill("spells", "necromancy");
        map_skill("parry","snowshade-sword");
        map_skill("sword","snowshade-sword");

        setup();

        carry_object(__DIR__"obj/sword1")->wield();
        carry_object(__DIR__"obj/tcloth")->wear();

}


void init()
{	
	::init();
	add_action("do_killing", "kill");
}

int do_killing(string arg)
{
    	object player, victim;
    	player = this_player();
    	if(!arg || arg == "") return 0;
    	victim = present(arg, environment(player));
    	if(!objectp(victim))
		return notify_fail("����û������ˡ�\n");
    	if(living(victim))
    	{
       		if(userp(victim)&& victim!=player)
        	{
            		message_vision(HIW"$N����$n�ȵ����ѵó���ɢɢ�ģ���Ȼ������С�ӻ�������!\n"NOR, this_object(), player);
            		this_object()->kill_ob(player);
            		player->kill_ob(this_object());
            		player->start_busy(2);
            		return 0;
        	} 
    	}
    	return 0;
}

int nec_book()
{
	object me,who;
	int i;
	me = this_object();
	who = this_player();
	i = REWARD_D->riddle_check(who,"��������");
	if (!i)
	{
		message_vision(CYN"$N˵��������˵ʲô������ô��������\n"NOR,me);
		return 1;
	}
	if (i != 3)
	{
		message_vision(CYN"$NĬĬ�Ŀ��ź�ˮ��һ�ﲻ����\n"NOR,me);
		return 1;
	}
	if (present("taoist feng",environment()))
	{
		message_vision(CYN"$Ņ��ͷ����$nһ�ۣ�������ֹ��\n"NOR,me,who);
		return 1;
	}
	who->start_busy(30);
	message_vision(CYN"$Ņ��ͷ����$nһ�ۡ�\n"NOR,me,who);
	call_out("do_ggyy",2,me,who,0);
	return 1;
}

void setlog(object me)
{
	int a,b,c;
	int i,j,x;
	string *msg = ({
"annie/demon_puzzle_lin",
"annie/demon_puzzle_huo",
"annie/demon_puzzle_san",
});
	string *msg2 = ({
"͵�������������ĵ���������",
"͵��������ڽ�Ǯ��ѧ�գ����㶼��֪����",
"͵����Ǹ���ؤ�����������������뻯��",
"͵����˲��ǿ�ޣ��������׵ġ�",
"��ָ��Ȼ��͵�飬��ָ͵����ʲô��",
"͵�飿��������ô�����ǰ����῵Ŀ�����Ϊ��",
});
	a = random(3);	
	b = random(2);
	switch (a)
	{
		case 0:
			if (b) 	{ b=1; c=2;}
			else	{ b=2; c=1;}
			break;
		case 1:
			if (b)	{ b=0; c=2;}
			else	{ b=2; c=0;}
			break;
		case 2:
			if (b)	{ b=0; c=1;}
			else	{ b=1; c=0;}
			break;
	}
	x = random(6);
	me->set(msg[a],"�����������У�˵�滰����ֻ��һ����");
	switch (x)
	{
	case 0:
		me->set(msg[b],"͵�����˵���Ǽٻ���");
		me->set(msg[c],msg2[random(6)]);
		me->set("annie/demon_puzzle",a+1);
		break;
	case 1:
		me->set(msg[b],"û��͵����˲�˵�ٻ���");
		me->set(msg[c],msg2[3+a]);
		me->set("annie/demon_puzzle",a+1);
				
		break;
	case 2:
		me->set(msg[b],"û��͵����˿϶�����˵�滰��");
		me->set(msg[c],msg2[b]);
		me->set("annie/demon_puzzle",c+1);
		break;
	case 3:
		me->set(msg[b],"û��͵����˿϶�����˵�滰��");
		me->set(msg[c],msg2[c]);
		me->set("annie/demon_puzzle",b+1);
		break;
	case 4:
		me->set(msg[b],"û��͵����˿϶�����˵�滰��");
		me->set(msg[c],msg2[3+b]);
		me->set("annie/demon_puzzle",b+1);
		break;
	case 5:
		me->set(msg[b],"û��͵����˿϶�����˵�滰��");
		me->set(msg[c],msg2[3+c]);
		me->set("annie/demon_puzzle",c+1);
		break;
	}
	return;
}

void do_ggyy(object me,object target,int count)
{
	string msg;
	string *event_msg = ({
"���羰�ĵ���˵�������Ȼ�ҵ����ˣ���Ҳ����ֱ�ԡ�",
"���羰�ĵ���˵��������ǰһ����·������¥��żȻ������λ�����������顣",
"���羰�ĵ���˵��������֮������Ǳ��͵��������������ʼĩ��",
"���羰�ĵ���˵����ԭ��������ָʹ��������һ�ˣ�����Ѱ���ƽ��ɽ�ڶ���ӡ֮����",
"���羰�ĵ���˵�������Ĵ���̽ȴ��Ѱ����һ��֮�¾�Ǳ�����¥��͵ȥ���Ǳ�"YEL"������ڡ�"NOR,
"���羰�ĵ���˵���������У���Ȼ����ʴ��֮����",
"���羰�ĵ���˵��������ԭ�����㽫�������º�͵͵�ͻ������ȴ�����ӿ�����",
"���羰�ĵ���˵���������Ӽ����ؼ�����ϲ֮�¾;�ֱȡ�ߡ�",
"���羰�ĵ���˵����ֽ���ڰ���ס�����ľٶ��ܿ챻������λ����֡�",
"���羰�ĵ���˵�����������ǱϾ�ʦ�ֵ�һ����Ҳ�ͻ������ڡ�",
"���羰�ĵ���˵������������ȴ���������ߵ����ӱ�����ץ����ֻ�ô�Ӧ�����ؿ���ƿ��",
"���羰�ĵ���˵������������Ȼ�������ң����÷���������п��ء�",
"���羰�ĵ���˵����лл������ɱ�˷���ˣ��Ҿͽ�������¸�������Ϊ����",
"���羰�ĵ���˵�����������幬�����ǲ����ٴ������Ծ��ڴˣ�ƶ��ʹ˸�ǡ�\n���羰�ĵ��ôҴ�ææ���뿪�ˡ�",
});
	if (!me || !target)
		return;
	if (environment(me) != environment(target) || me->is_fighting() || target->is_fighting())
		return;
	msg = event_msg[count];
	tell_object(target,CYN+msg+"\n"NOR);
	if (count < sizeof(event_msg)-1)
		call_out("do_ggyy",1+random(2),me,target,count+1);
	else
	{
		set("ggyying",0);
		setlog(target);
		target->stop_busy();
	REWARD_D->riddle_set(target,"��������",4);
		destruct(this_object());
		return;
	}
	return;

}


/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/

