#include <ansi.h>
inherit NPC;
int kill_object();

void create()
{
        set_name("���ŷ�", ({ "he yafeng","yafeng","he" }) );
        set("gender", "����" );
        set("age", 34);
        set("str", 40);
   
        set("long",
"������ȥ�����ʱ�����������Ͳ���̫�󣬳��÷ǳ�Ӣ�������ҷ�
�����棬��������\n\n");

        set("combat_exp", 100000);
        set("attitude", "friendly");
	set("fly_target",1);

        set("max_atman", 100);         
        set("atman", 100);             

        set("chat_chance", 1 );
        set("chat_msg", ({
"���ŷ����������ţ���Զ�Ϻ�ɽʯ��б����������˼ң�\n
ͣ������������˪Ҷ���ڶ��»�������������\n
��һƬ���ѽ����һ�����ڡ���\n\n",
        }) );

        set_skill("unarmed", 60);
        set_skill("dodge", 60);
        set_skill("force", 60);

        set("inquiry", ([
                "÷���": (:kill_object:),
                "��ʨ��": (:kill_object:),
		"�й�": (:kill_object:),
		"������": (:kill_object:),
		"���Ϲ�ĲƱ�": (:kill_object:),
        ]) );
		  
        setup();
        carry_object("/obj/armor/cloth")->wear();
}

int kill_object()
{	object meirujia;
	if (!this_player()->query("marks/meirujia"))
		{
			command("shake");
			command("say �Ҳ�֪������˵Щʲô��");
			return 1;
		}
	else
		{
			command(":P");
			command("say ԭ���㶼֪���ˣ���������û�ң�����û�㣡��");
			meirujia=new(__DIR__"meirujia2");
			meirujia->move(environment(this_object()));
			meirujia->kill_ob(this_player());
			destruct(this_object());
			return 1;			
		}
}
