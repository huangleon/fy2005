#include <ansi.h>
inherit NPC;

void create()
{
        set_name("�¶���", ({ "gu du mei", "gu du" }) );
        set("nickname", "���ײ���");
        set("title", "���д��");
        set("gender", "����");
        set("age", 56);
        set("no_arrest",1);
        set("long",	"һ�����ް߰׵��ˣ�˥�ϡ��㲡�ƣ�롢���˶��־塣\n");
        setup();
        carry_object("/obj/armor/cloth")->wear();
		carry_object(__DIR__"obj/sword")->wield();
}

void die(){
	say("�¶���˵�������ˣ�˭����������߳�ȥ��\n");
	::die();
}