#include <ansi.h>
inherit ITEM;

void create()
{
	set_name(HIW"ѩ��"NOR, ({ "snow ball" }) );
	set_weight(20);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("long", "ѩ�򰦣��������Կ��ɣ����ԣȣңϣף�");
		//set("no_split",1);
		set("no_transfer",1);
		set("value", 0);
		set("unit", "��");
	}
	::init_item();
}

void init()
{
	if(this_player()==environment())
		add_action("do_throw", "throw");
}

int do_throw(string target)
{
	if (!target) {
  	CHANNEL_D->do_sys_channel("info",this_player()->name()+"������"HIW"ѩ��"HIY"�ӳ���ֻ���� ž һ������"HIR"Hippe"HIY"������("HIG"�+1"HIY")��\n"NOR);
  } else
  {
		CHANNEL_D->do_sys_channel("info",this_player()->name()+"������"HIW"ѩ��"HIY"�ӳ���ֻ���� ž һ������"+HIR+target+HIY+"������("HIG"�+1"HIY")��\n"NOR);
  }
	log_file("HIPPO_DEBUG", sprintf("%s,%s,1,%s\n",this_player()->name(),this_player()->query("id"),ctime(time())));
	destruct(this_object());
	return 1;
}