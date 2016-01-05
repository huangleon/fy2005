// apstone, inc. c 1998
#include <ansi.h>
inherit NPC;
void create()
{
        set_name("�", ({ "lee", "lee bao" }) );
        set("long","
�½������������ϰ壬�˼Ҷ�����Ϊ�����ϴ󣢣���ܵ�������ο��
���ɣ�������װ�ο��Ǹ������һζ̰ǮС��������\n");
		set("gender","����");
		set("age", 39);
		set("no_arrest",1);
        set("combat_exp", 100000);
		set_skill("unarmed",100);
		set_skill("luohan-quan",100);
		map_skill("unarmed","shuaijiao");
        set("chat_chance", 1);
        set("chat_msg", ({
                "�����ȱ���ӻ�ô������װ�Σ�work����һ��һ�����ӣ�\n",
                "�ָ���㣺��͵������ɻ\n",
        }) );
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

void init()
{
        ::init();
        add_action("do_work", "work");

}

int do_work(string arg)
{
        object ob;
        object me;
        me = this_player();
	
		if (query("worked")>20)
			return notify_fail("�˵�������һ���䣬�����ټ����й���\n");
			
		if(me->is_busy()) 
			return notify_fail("��Ķ�����û����ɣ����ܹ�����\n");
		message_vision("$Nװ����һ���Σ�����Ҳ�۵�Ҫ����\n",me);
		tell_object(me,"�㿿���γ��Ժ����ش��Ŵ�����\n");
		
		if (random (me->query("kar"))>10 && !environment()->query("already")) {
			tell_object(me,"��ע�⵽����ĳ�����ο���Щ�ɶ�������г��ֵĹ���Ҳ����Ծ�������\n");
			me->set_temp("marks/xj_noticed_salt",1);
		}
		add("worked",1);
		
		me->receive_damage("gin",120,me);
		me->receive_damage("sen",120, me);
		me->set_temp("last_damage_from","���½����иɻ����۹��ȶ�����\n");
		ob = new("/obj/money/silver");
		
		if (!ob->move(me))
			ob->move(environment(me));		
		message_vision("���Ц����������$N˵��������Ĺ�Ǯ��\n", me);
		
		 if (QUESTS_D->verify_quest(me,"�½�װ��")) 
		 	QUESTS_D->special_reward(me,"�½�װ��");
		
		me->perform_busy(2);
		return 1;
}


void reset(){
	set("worked",0);
}