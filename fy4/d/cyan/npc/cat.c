#include <ansi.h>
inherit NPC;
void create()
{
    	set_name("Сɽè", ({ "little cat", "cat" }) );
        set("race", "Ұ��");
        set("age", 1);
        set("gender", "����");
        set("long", "һֻСС�ģ����Żư׻��Ƶ�Сè����ſ��Ϫ�ߺ�����Ĵ���ˮ����\n");
    	set("combat_exp", 20000000);
    	set("max_kee",500);
    	set("max_gin",500);
    	set("max_sen",500);
		set("str",1);
		set("force_factor",0);
        set("attitude","peaceful");
        set("limbs", ({ "ͷ��", "����","β��" }) );
    	set("verbs", ({ "bite","claw" }) );
		set("chat_chance", 1);
		set("chat_msg", ({
			"Сɽè�����̧ͷ�����㡣\n",
			"Сɽè������Ľ�����һȦ����������������ȥ��\n",
			"Сɽèƫ��ͷ�����㣬̧��צ��ָָϪˮ��\n",
		}));	
        setup();
}

int accept_object(object who, object ob)
{
    if(ob->query("marks/catfood"))
    {
        message_vision(sprintf(
            "$N���˹�������������ְ�%s�����ˡ�\n", ob->name()),this_object());
        return 1;
    }
	return notify_fail("Сɽè��ͷ�����ᣬת�����˿�ȥ��\n");
}
        
void init(){
	::init();
	add_action("do_look", "look");
}


int do_look(string arg) {
if (!arg)
	return 0;
	if(present(arg,environment()) == this_object()){
		write("һֻСС�ģ����Żư׻��Ƶ�Сè����ſ��Ϫ�ߺ�����Ĵ���ˮ����
��СģС���ġ�
���������ų������죬�书����������"+BLU "����һ��"NOR+"�������ƺ����ᡣ
��"HIG"�������ϲ���˿���˺ۡ�"NOR"\n");
		return 1;
	}
	return 0;
}