#include <ansi.h>
inherit ITEM;
void create()
{
    set_name( HIY "ϲ�����" NOR, ({ "hongbao" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("lore",1);
            //set("material", "cloth");
            set("long", "һ���Ĺĵĺ��������ӡ�ţ�HIPPOǮׯ��������\n");
          }
    ::init_item();
}

void init()
{

	if(environment()==this_player())
		add_action("do_open","open");
}

int do_open(string arg)
{
	object gold;
	int goldnum=0;
	if(arg != "hongbao" && arg != "ϲ�����") return 0;
	if(this_player()->query("partymarks/newyear/hongbao")) {
		tell_object(this_player(),HIR"HIPPO"NOR"�������ڶ��߻ص���"YEL"̰�Ĳ��㣬���û��!\n"NOR);
		destruct(this_object());
		return 1;
		//return notify_fail("���С������������ǿյģ�\n");
	}
	if (F_LEVEL->get_level(this_player()->query("combat_exp")) >= 20) {
		goldnum=F_LEVEL->get_level(this_player()->query("combat_exp"))*2/3+random(F_LEVEL->get_level(this_player()->query("combat_exp"))*2);
	} else {
		goldnum=F_LEVEL->get_level(this_player()->query("combat_exp"))/2+random(F_LEVEL->get_level(this_player()->query("combat_exp"))/2);
	}
	if (goldnum >= 1 && F_LEVEL->get_level(this_player()->query("combat_exp")) >= 10) {
		gold = new("/obj/money/gold");
		gold->set_amount(goldnum);
		gold->set("name","����Ҷ��");
		gold->set("base_unit","��");
		gold->move(this_player());
		this_player()->set("partymarks/newyear/hongbao",1);
	} else {
	 goldnum=0;
	}
	//set("opened",1);
	//return notify_fail("���С������������ó����Ŵ���Ҷ�ӣ�\n");
	if (goldnum == 0 || F_LEVEL->get_level(this_player()->query("combat_exp")) < 10) {
		CHANNEL_D->do_sys_channel("info",this_player()->name()+"���ֽ�"+this_object()->name()+HIY"�۳�ֽ�ɻ����˳�ȥ��\n"NOR);
	} else {
		CHANNEL_D->do_sys_channel("info",this_player()->name()+"ĬĬ�����"+this_object()->name()+HIY"���������ó�"+goldnum+"�Ŵ���Ҷ�ӡ�\n"NOR);
	}
	if (goldnum == 88 || goldnum == 188 || goldnum == 288 || goldnum == 388) {
		this_object()->set("name",HIM"���˲����"NOR);
		this_object()->set("long", "�������������������ӡ�ţ�HIPPOǮׯ��������\n");
		this_player()->set("partymarks/newyear/hongbao",0);
		CHANNEL_D->do_sys_channel("info",this_player()->name()+"�ܵ��˲���Ĺ�ˣ�������"+this_object()->name()+HIY"��Ϊ������\n"NOR);
	} else {
		destruct(this_object());
	}
	return 1;
}
