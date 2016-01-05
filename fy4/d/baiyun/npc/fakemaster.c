// master.c

inherit NPC;
inherit F_MASTER;
#include <ansi.h>
void create()
{
        set_name("Ҷ����", ({ "ye wanren", "ye" }) );
        set("nickname", RED"һƬ�³�����ɽ"NOR);
        set("long",
"���������ݳ�ª��һ˫�۾���������ݣ���ȻҲĿ���Ƶ磬����ʵ�м���
��������֮�⡣\n"
	);
        create_family("���Ƴ�",2, "������");
		set("rank_nogen",1);
    	set("ranks",({"��ʹ","��ʹ","��ʹ","��ʹ","��ʿ",CYN"��ʹ"NOR,CYN"��ʦ"NOR,HIC"��ʦ"NOR}));
        set("combat_exp", 2000000);
        set("score", 200000);
    	set("reward_npc", 1);
		set("difficulty", 5);
        set("gender", "����" );
        set("class","baiyun");
        set("age", 44);
	    set("per", 40);
        set("chat_chance_combat", 20);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianwaifeixian" :),
        }) );
		set("attitude","friendly");
        set("max_force", 8000);
        set("force", 8000);
        set("max_kee",8000);
        set("max_gin",8000);
        set("max_sen",8000);
        set("chat_chance", 1);
        set("chat_msg", ({
                "Ҷ�³���������֮�������۳���΢΢һЦ�����Ͻ�֮�ߣ�һ��������\n",
        }) );

        
        set_skill("move", 150);
		set_skill("daode",150);
        set_skill("parry", 120);
        set_skill("dodge", 150);
        set_skill("force", 160);
        set_skill("literate", 130);
		set_skill("sword", 140);
		set_skill("unarmed",120);
		set_skill("changquan",120);
		set_skill("feixian-steps",140);
		set_skill("feixian-sword",140);
		set_skill("chessism",60);
		
        map_skill("dodge", "feixian-steps");
		map_skill("sword", "feixian-sword");
		map_skill("parry", "feixian-sword");
		map_skill("unarmed", "changquan");
		map_skill("force","chessism");

        setup();
        carry_object(__DIR__"obj/yemask")->wear();
        carry_object(__DIR__"obj/whitecloth")->wear();
        carry_object(__DIR__"obj/xiaolian")->wield();

}


void init()
{       
        object ob;
        ::init();
        if ( interactive(ob = this_player()) && !is_fighting() ) 
           {
             remove_call_out("greeting");
             call_out("greeting", 1, ob);
           }
		 	add_action("do_enjoy","join");

}


int do_enjoy()
{
	object me = this_player();
	if (REWARD_D->riddle_check(this_player(),"��ͼһ��") !=8 
		&& REWARD_D->riddle_check(this_player(),"��ͼһ��") !=9 )
		return 0;
	ccommand("emote ���۳��ף���Ȼ�������뽣����ԣ�������Ϊ������Ρ�");
	REWARD_D->riddle_set(me,"��ͼһ��",9);
	return 1;
}

void greeting(object ob)
{
        object corpse;
        if( !ob || environment(ob) != environment() ) return;
		if (REWARD_D->riddle_check(ob,"��ͼһ��") !=7 
			&& REWARD_D->riddle_check(ob,"��ͼһ��") !=8)
			return;
		tell_object( ob, CYN"
Ҷ�³Ǻ���һ��˵����֪�����⡣����Ϊ�����߲���С�ڣ���Զı�߲�ͼ
С���������������������ʲô��ʱֵ��������(join)�Ұ��Ƴǣ���ǧ��
��ҵ����Ϊ����֮ѡ��\n\n"NOR);
		REWARD_D->riddle_set(ob,"��ͼһ��",8);
		return;
}


void re_rank(object student)
{
	int exp;
	exp = student->query("combat_exp");
	if( exp <= 1200000 )
	{
			::re_rank(student);
			return ;
	}
	student->set_temp("annie/by_fight_ss",1);
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
