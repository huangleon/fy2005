#include <ansi.h>
#include <command.h>
inherit SMART_NPC;

void create()
{

	set_name("������",({"long wang","wang"}));
    set("title","����һ��");
    set("long", "������������������ϺƬ���ŵķ��ţ�����һ�����Ĩ���졣��ϲ���������Ϻ��
�����������ݺ��ߺ�ʱ���ɵ�ϰ�ߣ�����ʳ�������������������档��\n");
	set("age",40);
	set("combat_exp", 4000000);
        	
	set("reward_npc", 3);
		
	set("chat_chance", 1);
    set("chat_msg", ({
        	"�����������ȥ������Ů�����������������Ц�ˡ�\n",
        	"��������������ļ�˵��Ů�˵ĺ������������������������������ӣ��������˵ġ�\n",
        }) );

	
   	set("chat_chance_combat", 100);
    set("chat_msg_combat", ({
	     (: auto_smart_fight(20) :),
       }) );
    	    	
    auto_npc_setup("wang",200,180,0,"/obj/weapon/","fighter_w","shenji-blade",1);
	setup();
	carry_object(__DIR__"obj/7blade")->wield();
}


void init()
{
    ::init();	
    add_action("do_look", "look");
}


int do_look(string arg)
{
    object me,girl;
    me = this_player();
    
    if (girl=present("naked girl",environment(this_object())))
    if( arg == "naked girl" || arg == "girl" )
    {
        message_vision(CYN"$N��������ļ��˵����ô������ɫ�ɲͣ��õ��������������ô�����ô�档\n\n"NOR, this_object());
        return 0;
    }
    else return 0;
}

int accept_object(object who, object ob)
{
	if( ob->value() >= 10000) {
        command("spank "+this_player()->get_id());
        who->set_temp("taiping/longwang_kill",1) ;
        message_vision(CYN"���������˸���ͷ������һ����������������˸����ơ�\n"NOR,who);
        command("say �ã��������ӻ�����ζ���Ϳ�������ô��Ū��С��ˡ�\n");
        return 1;
	} else {
    	command("shake");
    	command("say ��ֵ��ô�㣿");
        return 0;
	}
       return 0;
} 

