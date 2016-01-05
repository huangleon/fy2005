#include <ansi.h>
inherit NPC;

void create()
{
    	set_name("����", ({ "ding feng", "ding", "feng" }));
    	set("long", "��������������ƮƮ�������������������Ҳ���ú�Ӣ����
���ϸ���Զ������Ц�ݡ�\n" );
 	set("nickname", HIC "�����ٷ�" NOR);
 	set("gender", "����");
 	set("age", 27);
 	set("no_arrest",1);
	
	set("class","huashan");
 	set("combat_exp", 800000);
 	set("attitude", "friendly");

 	set("chat_chance", 1);
 	set("chat_msg", ({
"�����૵�����ɽ����һ�ס����ʮ��ʽ����ȷ�����������������ܼ���
�����صġ��������ʽ�����������硣\n ",
"����΢Ц���������ʮ��ʽ��������ڡ��嵭������,���������ǣ��������ޣ�
��ʵ���飬�Ʊ�δ�� ��\n",
 }) );
 	set("inquiry",([
  		"���ʮ��ʽ" : "�����˻�ɽ��ɽ֮��������ȴʧ���ˣ�����\n",
 	]) );
	
	set_skill("unarmed", 150);
	set_skill("move", 100);
	set_skill("dodge", 150);
	set_skill("parry", 100);
	set_skill("force", 100);
	set_skill("sword", 100);
	set_skill("hanmei-force",100);
	set_skill("qingfeng-sword", 140);
	set_skill("anxiang-steps", 100);
	
	map_skill("force","hanmei-force");
    map_skill("move", "anxiang-steps");
	map_skill("parry", "qingfeng-sword");
	map_skill("sword", "qingfeng-sword");
        map_skill("dodge", "anxiang-steps");

	setup();
    	carry_object("/obj/armor/cloth")->wear();
    	carry_object("/obj/weapon/sword")->wield();

}


int accept_object(object who, object ob)
{
    	object room;
    	
    	if (who->is_busy()){
    		ccommand("say ���Ժ�Ƭ�̣�������ͷ���¶�������ɡ�");
    		return 0;
    	}
    	
    	if((string) ob->query("id") == "qing feng book")
    	{
	 		command("smile");
	  		command("say �ã���������������Ҫ�ҵ����ˣ����ϴ������¹������ȥ��\n");
	  		tell_object(who, GRN "���ϲ��������������������˴󺣴�.......\n\n" NOR ) ;
	  		message_vision("����һ�������ϴ���æ����һ��������ඣ�\n", who);
	  		message_vision("�������𷫣������򶫷����С�\n\n", who);
	  		room = find_object(AREA_BAT"dahai");
	  		if (!room)	room = load_object(AREA_BAT"dahai");
	  		who->move(room);
	        	return 1;
	    	}
    	else 
    		message_vision("�����$N˵�������������ûʲô��ϵ��\n", who);
    	return 0;
}
