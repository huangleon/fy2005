// ; annie 07.2003
// dancing_faery@hotmail.com
#include <ansi.h>
inherit ITEM;
void create()
{
    set_name(WHT"ǧ����¶"NOR, ({ "dew drop","dew" }) );
    set_weight(1);
    if( clonep() )
            set_default_object(__FILE__);
    else {
            set("unit", "��");
            set("material", "water");
            set("long", "һ�ι����ŵľ�Ө¶ˮ���ݴ�ǧ��һ�ᣬ����ޱȡ�\n");
			set("real",1);
			set("value",2000);
          }
	::init_item();
}

void init()
{
	call_out("dissolve",60);
}

int dissolve()
{
	object holder,room;
	if(!objectp(holder=environment())) {
		destruct(this_object());
	}
	if(userp(holder))
		room=environment(holder);
	else room=holder;
	message("vision",this_object()->query("name")+"������������ʧ�ˡ�\n",room);
	destruct(this_object());
	return 1;
}