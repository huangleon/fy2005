// XXDER@FY3
inherit NPC;
#include <ansi.h>
void create()
{
    set_name("��ū" , ({ "swords slave","slave" }) );
    set("nickname",CYN"ǧ�ذ��ƿ�����"NOR);
    set("long", "�����Ƶ�Ϊ��֪��ʱ�����������û��֪�����������ϣ�Ҳû��֪������Ҷ\n�³ǵĹ�ϵ��ֻ֪������û�����������ڽ��ַ�����Ҳû��������̤����Ƶ�\nǱ��Ȫһ���������ƺ�ֻ�Ǿ�������������ɨ��ڣ���ո�һ�գ��긴һ�ꡣ\n");
	set("attitude", "friendly");
    set("age", 132);
        set("gender", "����" );
        create_family("���Ƴ�",1, "��ڣ�ػ���");
        set("chat_chance", 1);
        set("chat_msg", ({
        "��ū���ű�������������ز����Ž����е�ÿһ�ѽ���\n",
        }) );
    set("per",10);
    set("combat_exp", 30000000);
    set_skill("dodge", 200);
    set_skill("fall-steps", 200);
    set_skill("sky-sword", 200);
    set_skill("sword", 200);
    set_skill("unarmed", 100);
    set_skill("iron-cloth", 100);
    set_skill("henglian", 200);
    map_skill("iron-cloth","henglian");
    map_skill("sword","sky-sword");
        set("chat_chance_combat", 30);
        set("chat_msg_combat", ({
                (: perform_action, "sword.tianrenheyi" :),
        }) );

	setup();
    carry_object(__DIR__"obj/mayi")->wear();
        carry_object(__DIR__"obj/broom")->wield();
}

/*

void init()
{
	::init();
	add_action("do_gogo", "go");
}


int do_gogo(string arg)
{
	object me;
	me = this_player();
	if( arg == "westdown" )
	{
	if( me->query("class") ) 
		if( me->query("class") != "baiyun") {
		command("emote ΢΢̧��̧�����İ�ü��ɨ��һ�ۣ�����һ�����������ߣ�����");
		write("��������·����ס�� ��\n");
		return 1;
		}
		else
			return 0;		
	}
	return 0;
}
*/
/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
