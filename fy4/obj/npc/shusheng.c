// teacher.c
#include <ansi.h>

inherit NPC;

void create()
{
        
        string *order = ({"��", "��", "��", "��", "��", "��", "֣", "��", "��",
"��", "��", "��", "��", "��", "��", "κ", "��", "��", "��", "��"});
	string *orderr = ({"����", "���", "�ô�", "����", "����",
"ŷ��", "����", "����"});
        string *poem = ({"��ĸ�����ߣ����������¡��������ܷ죬��ֳٳٹ顣˭�Դ���ģ����������͡�\n",
        		"��ī��Ϊ�飬���������ס���ȥ����ȥ��أȻ��һ��\n",
        		"һϦ����ൣ��ζ̲����ҡ��ٶȳ���İ���ս��������\n",
        		"������������䣬�񳯷ŵ�˼���ġ�����������㼲��һ�տ�����������\n",
        		"�ߵش����㣬ʮ���һ������ʱ�����Σ���ĺ�ķ�ɳ��\n",
        		"�����仨�����죬�Ϸ���������ǰ�����������೯�ˣ�Ψ�ҹ���μˮ�ߡ�\n",
        		"ȥ���ᴦ�񴺹飬������������ϡ����ЦƬʱĺ����������һ�����ԡ�\n",
        	});



        set_name( order[random(20)] + orderr[random(8)], ({ "shusheng", "sheng" }) );
	
	set("title", "�������");
	set("gender", "����" );
	set("age", random(20)+20);
	set("int", 26);
	set("long",
		"���Խ���Ϊҵ��\n");
		
        set("chat_chance", 1);
        set("chat_msg", ({
                (: random_move :),
                CYN""+name()+"ҡͷ���Ե�������"+poem[random(7)]+""NOR,
        }) );

	set("attitude", "peaceful");
	
	set_skill("literate",40);
	set_skill("dodge",50);
	
	set("combat_exp", 5000);
	
	setup();
	carry_object("/obj/armor/cloth")->wear();
}


int random_move()
{
        mapping exits;
        string *dirs;
	string thisdir;
        
        if (query_temp("random_move")>= 160 && query("startroom") && !query("no_return")) {
		if (return_home(query("startroom")))
			delete_temp("random_move");
		return 1;
	}
        if( !mapp(exits = environment()->query("exits")) ) 
	{
		destruct(this_object());
		return 0;
	}
        dirs = keys(exits);
	thisdir = dirs[random(sizeof(dirs))];
	this_object()->set("last_dir",thisdir);
        command("go " + thisdir);
        add_temp("random_move",1);
}
