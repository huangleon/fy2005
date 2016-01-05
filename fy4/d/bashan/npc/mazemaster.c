// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;


void create()
{
		object weapon;
        set_name("��·��", ({ "maze master","master" }) );
        set("long","һ�������糾�ĺ��ӣ������˫�۽����ض����㣬�㲻������һ��������\n");
        
        set("title",CYN"����� ��¹"NOR);
        set("gender", "����" );

		set("age",47);
		set("skill_public",1);

		set("chat_chance",1);
		set("chat_msg", ({
			"��·��������ʣ���̾������¹����·��·��ƽ��¹���У������Ѱ�����\n",
		}) );

        set("combat_exp", 10000000);

		set_temp("busy_immune",2);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform luoxiang") :),
             }) );

		set("inquiry",([
			"����֮��": CYN"ȥ"WHT"��ϼɽ"CYN"�����߿����ɡ�",
    	]) );

        set_skill("sword", 400);
        set_skill("pathfinding", 200);
        set_skill("theorem",20);
        set_skill("dodge", 200);
        set_skill("parry", 200);
        set_skill("windsword", 320);
        set_skill("13-sword", 220);

        map_skill("sword", "windsword");
        map_skill("parry", "windsword");
        map_skill("dodge", "13-sword");

		setup();

        weapon=carry_object("/obj/armor/cloth");
		weapon->wear();

		carry_object("/obj/weapon/sword")->wield();

}

int prevent_shown(object me, string skill)
{
	if (skill == "pathfinding" || skill=="theorem")
		return 0;
	
	return 1;
}

int recognize_apprentice(object ob)
{
	object room2;
	
	if (F_LEVEL->get_level(ob->query("combat_exp"))<10){
		message_vision("��·��ҡͷ˵���������̫ǳ����ѧ�����ҵ���·���飨������ȼ�10��\n",ob);
		return 0;
	}
	
	if (ob->query("timer/mazemaster")+1830> time()) {
		message_vision("��·��ҡͷ˵����ող��������ٵ���"+ (ob->query("timer/mazemaster")+1800-time())/60+"���Ӱɡ�\n",ob);
		return 1;
	}
	
	if (ob->query("quest"))
	{ 
		message_vision("��·��ҡͷ�������������£�quest��������ȥ�˶�Ǭ���������Ұա�\n\n",ob);
		return 0;
	}

	message_vision("��·��΢΢һЦ��Ҫѧ��·����ô���ðɣ��ǾͿ�������û�б����ҵ����ˣ�\n\n",ob);
	message_vision(WHT"��·����һ���֣�һ��������������$N"NOR+WHT"��û���С�\n\n"NOR,ob);
	ob->set("timer/mazemaster",time());

		room2=find_object("/obj/dungeon/maze/"+ob->query("id")+"/entry");
		if (room2)
		{
			room2->destruct_maze();
			room2=find_object("/obj/dungeon/maze/"+ob->query("id")+"/entry");
		}
		if (!room2)
			room2=load_object("/obj/dungeon/maze/"+ob->query("id")+"/entry");
		if (!room2)	
			room2="/obj/dungeon/maze"->query_maze_room(ob->query("id")+"/entry");

	ob->move(room2);
   	return notify_fail(" ");
}

/*

���������������X�Y
���������������U�t�r
���������������U���t�r
���������������U�����t�r
���������������U��������
���������������^�k�k�k�_

��������������- FengYun - ������
������������annie 08.2003
������dancing_faery@hotmail.com
*/


