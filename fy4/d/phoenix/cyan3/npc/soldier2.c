#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
        set_name("��ϼ�ر���", ({ "fengyun garrison", "garrison" }) );
        set("long","
���Ǹ�����ִ���س������ֵ�ڱ�����Ȼ����������������������ЩС��
���书ʵ��ƽ����������������֯���м��ɵ�սʿ��˭Ҳ�����׵��������ǡ�\n"
"[31m�����Ҳ��Ҫ�������ǡ� [32m\n");
        set("attitude", "heroism");
	set("no_heal",1);


	set("chat_chance", 1);
	set("chat_msg", ({
		CYN"��ϼ�ر�������һ��ɽ��һ��Ѫ���ֵܽ�����Ǵ��������������ˣ�\n"NOR,
		CYN"��ϼ�ر��������ֵ���ǧ����ס���������һ������Щ���ӿɾ��ܳ���ֱ�룬Ѫϴ��ԭ�ˣ�\n"NOR,
	}) );

        setup();

        carry_object(__DIR__"obj/kiujia")->wear();
        carry_object(__DIR__"obj/longdagger")->wield();
}


