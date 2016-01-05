// annie 07.2003
// dancing_faery@hotmail.com

#include <ansi.h>
inherit SMART_NPC;
int leave();


void create()
{
		object weapon;
        set_name("��·��", ({ "maze master","master" }) );
        set("title",CYN"����� ��¹"NOR);
        set("gender", "����" );
		set("long","һ�������糾�ĺ��ӣ��˿�����Ц���еؿ����㣬�ƺ�������������ġ�\n");

		set("age",47);
		set("NO_KILL","ɱ�������Զ�ء���Զ�ء���Զ�����������ˡ�������\n");
		set("skill_public",1);

		set("chat_chance",1);
		set("chat_msg", ({
			"��·��������ʣ���̾������¹����·��·��ƽ��¹���У������Ѱ�����\n",
			"��·��˵������������뿪(Leavenow)�ˣ�\n",
		}) );

		set("inquiry",([
			"leavenow": (: leave :),
			"����֮��": CYN"ȥ"WHT"��ϼɽ"CYN"�����߿����ɡ�",
    	]) );

        set("combat_exp", 10000000);

		set_temp("busy_immune",2);

        set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
                (: ccommand("perform luoxiang") :),
        }) );

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

void init(){
	if (interactive(this_player())){
		ccommand("say ������η��������·����֮���������˴��ˣ�");
		add_action("leave","leavenow");
	}
	return;
}

int prevent_shown(object me, string skill)
{
	if (skill == "pathfinding"|| skill=="theorem")
		return 0;
	
	return 1;
}


int prevent_learn(object me, string skill)
{
  	if (skill != "pathfinding"&& skill!="theorem")
  	{
      		command("emote ҡͷ̾���������Ѱ���������");
      		return 1;
  	}
  	return 0;
}


int recognize_apprentice(object ob)
{
	return 1;
}


int leave()
{
	object me = this_player();
	object wer;
	
	if (me->is_busy()) {
		tell_object(me,"��������æ���ء�\n");
		return 1;
	}
	
	command("wave "+me->query("id"));
		
	wer = find_object("/d/fycycle/sroad5");
	if (!wer)
		wer = load_object("/d/fycycle/sroad5");
	me->move(wer);
    return 1;
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



