#include <ansi.h>
inherit __DIR__"in.c";

void create()
{
	object weapon;
        set_name("�䵱����", ({ "dizi"}) );
        set("long","���Ÿ����𳤵���ϼɽ�μ���Ѫƽ�ܴ����޲��ǰ�����һ�ľ�Ӣ��\n���ǵ���ѧ�����ڽ�����ͨ���������˼���\n");
        set("attitude", "heroism");

		set("death_msg",CYN"\n$N��������ʦ�֣�������\n"NOR);
	set("no_heal",1);

        setup();
        weapon=carry_object("/obj/weapon/sword");

		weapon->wield();

        weapon=carry_object("/obj/armor/cloth");
        weapon->set_name("��ɫ����", ({ "cloth" }) );
		weapon->set("long"," ");
		weapon->set("no_get",1);
		weapon->set("value",0);
		weapon->wear();


}


