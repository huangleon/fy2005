#include <ansi.h>
inherit QUESTNPC;
int give_mail();
void create()
{
        set_name("Ѧ�ɿ�", ({ "xue keke","xue" }) );
	set("nickname",HIC"�¹���ˮ"NOR);
        set("title","����ɽׯ   ��С��");
	set("gender", "Ů��");
        set("quality","good");
        set("age",19);
        set("combat_exp", 5800000);
         set("long",
"��ɫˮ���䣬�·��в㵭�����������������·���һ����������Ӱ���ƿ���
���֣��¹�̸������������ǡ�������������ϡ��԰׵Ĺɣ��԰����¡�\n"
        );
        set("max_force",5000);
        set("force",5000);
        set("force_factor",150);
		set("max_gin",3200);
		set("max_sen",3200);
		set("con",40);
		set("int",27);
        set_skill("move",150);
        set_skill("parry", 200);
        set_skill("blade",200);
        set_skill("dodge",150);
		set_skill("moon-blade",120);
        map_skill("dodge","moon-blade");
        map_skill("blade","moon-blade");
        map_skill("parry","moon-blade");
        set("chat_chance", 15);
        set("chat_msg", ({
 "Ѧ�ɿ�����źڰ��Ĳ�񷵭���ص�����̫���������������������Ŵ�ʱ
�˿̣�����һ��С¥�ĵƹ��£���Ҳһ���ڵȴ�����������\n",     }) );


        set("chat_chance_combat", 70);
        set("chat_msg_combat", ({
			(:perform_action,"blade.yueshen-feidao":),
        }) );
		set("inquiry",([
			"�":(:give_mail:),
			])	);
        setup();
        carry_object(__DIR__"obj/yueshencloth")->wear();
        carry_object(__DIR__"obj/yueshenblade")->wield();
}

int give_mail()
{		object letter;

		command("sigh");
		command("say ���±�������������飬��ʱ��ʹ֪�����ԣ�Ҳ������ȥ��");
		if(!this_object()->query("mail_given"))
		{
			letter=new(__DIR__"obj/zhanshu");
			message_vision("$N��$n˵����������Ұ�����Ž��������",this_object(),this_player());
			letter->move(this_player());
			this_object()->set("mail_given");
		}
		return 1;
}