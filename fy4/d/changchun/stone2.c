#include <ansi.h>
#include <room.h>
inherit DOOR_ROOM;

void create()
{
	set("short", "�ص�");
	set("long", @LONG
�ص����ԣ�ÿ��ʮ��������һյʯ�ƣ�������ʮ�������ǵ�����ʯ�ţ��ʹ���
���೤����
LONG
	);
	set("exits",([
		"up" :__DIR__"stone1",
		"west" : __DIR__"stone3",
	
	]) );
	set("coor/x",-90);
	set("coor/y",-20);
	set("coor/z",-30);
	setup();
	create_door("west","door","����ʯ��","east",DOOR_CLOSED);
}

void init()
{
	add_action("do_bomb","bomb");
}


int do_bomb(string arg)
{
        object  me, *inv, exp, nroom;
        int     i;

        me = this_player();
        inv = all_inventory(me);
        for(i=0; i<sizeof(inv); i++)
                if( (int) inv[i]->query("explosive") ) exp = inv[i];
        if( !exp)  return 0;
        	
        message_vision(HIR"$N��ȼ�����е�"+exp->name()+"������
ֻ����һ��������죢�䣢�����ڱ�ը�����󶴣�\n"NOR, me, exp);
        destruct(exp);
        nroom = find_object(__DIR__"rock0");
        if(!objectp(nroom))
        	nroom = load_object(__DIR__"rock0");
        inv = all_inventory(this_object());
        
        for(i=0; i<sizeof(inv); i++) {
        	if(userp(inv[i]) ) {
            	tell_object(inv[i],BLU"������������������ε�ת�����û�ι�ȥ��\n"NOR);
            	inv[i]->set("gin",0);
            	inv[i]->set("sen",0);
            }
        }
        
        me->move(nroom);
        return 1;
}
