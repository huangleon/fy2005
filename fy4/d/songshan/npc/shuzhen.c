// Copyright (C) 1995, by Tie Yu and Daniel Yu. All rights reserved.
// This software can not be used, copied, or modified in any form without
// the written permission from authors.
inherit NPC;
#include <ansi.h>
int kill_him();
void create()
{
        set_name("Ҷ����", ({ "ye shuzhen", "ye"}) );
        set("nickname", HIR "ǰ�ΰ�������"NOR);
        set("gender", "Ů��" );
        set("age", 44);
		set("per", 55);
        set("int",30);
		set("attitude","friendly");
        set("long","Ҷ������ؤ���ǰ�ΰ����δȵķ��ˣ�ȴ��֪Ϊ���ڴˡ�\n");
        set("combat_exp", 4000000);
        set("inquiry", ([
                "�Ϲ���" : (: kill_him :),
                "master nangong" : (: kill_him :),
                "�δ�":		"�δ����ҷ����\n",
                "������":	"actionҶ�����������ţ�һ�ﲻ����\n",
        ]));
        setup();
        carry_object(__DIR__"obj/blackcloth")->wear();

}

int kill_him()
{
	command("say �Ϲ�������ΪТ˳��ÿ������һ�룬��δ��ϣ�\n");
	return 1;
}

int accept_object(object who, object ob)
{
	if(ob->name() == "�����ܺ�"){
        command("say ��д����Ҳ���򲻵��ԣ��Ϲ�Ұ�Ĳ������۶�ؤ�����
֮λ�������������ڴˣ��������˽���Ѷ�����ҷ򣬲�֪�����͵���\n");
		return 0;
	}
    return 0;
}

