#include <ansi.h>
inherit SMART_NPC;
int kill_him();

void create()
{

	set_name("Ѧ��",({"xuebin"}));
    	set("title",YEL"�ú�ׯ��ׯ��"NOR);
    	set("long", "
Ѧ��̧������ס�죬����ؿ����ţ��������������ϣ���Ȼ��ֻ�����Ǹ���
���������⣬�������о��У�ȴ������Ϧ�������Լ�ȴ��Ϧ�����޺õ�ʱ��
���ѹ�ȥ�����������ѵ�����ҹ����\n");
	set("age",69);
	set("combat_exp", 5500000);
        set("attitude", "heroism");
	
	set("inquiry", ([
             "������" : (: kill_him :),
       	]));
	
	set("chat_chance_combat", 100);
        set("chat_msg_combat", ({
	       	(: auto_smart_fight(20) :),    
        }) );
	
	auto_npc_setup("xuebin",200,180,1,"/obj/weapon/","fighter_w","xuanyuan-axe",1);
	setup();
	carry_object("/obj/armor/cloth")->wear();
	if (!random(10)) carry_object(BOOKS"axe_75");
}


int kill_him()
{
        object me, another;
        
        me = this_player();
 	if (this_object()->is_fighting()) {
 		tell_object(me,"Ѧ������û�ջش��㡣\n");
 		return 1;
 		}
        message_vision(CYN"
Ѧ��������Ǵ����������£���Ȼ�����������䣬���������ص�ʮ����ǰ��
�һ��ǻ���ͬ�����ġ���������Ϊ������ʵ�ڲ��Ǹ���������\n"NOR,this_object());
        return 1;
}