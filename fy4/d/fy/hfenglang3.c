
inherit DOOR_ROOM;
#include <room.h>

void create()
{
    set("short", "佻˳���");
    set("long", @LONG
�����Ǹ��������С���Ǹ�����ԡ�ģ����������ʮɫ�Ĳʴ�����ζ�˱ǵĻ�
�꣬������������ض��ǣ�͸������ˮ�����Կ���������������޳��Ĵ��ȣ���
ͦ�����ţ����ںڵĳ���������������
LONG
    );
    set("exits", ([
	"north" : __DIR__"hfenglang2",
	"south" : __DIR__"hfengpool",
      ]));
    set("objects", ([
	__DIR__"npc/smileboy": 1,
      ]) );
    set("coor/x",-80);
    set("coor/y",-255);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    create_door("south","door","̴ľ��", "north", DOOR_CLOSED);

}


int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    int withtowel=0;
    int weartowel=0;
    
    if( dir == "south" && ob=present("jin tong", this_object()) )
    {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{    
		    if( (string)(inv[i]->query("id")) == "white towel" ){
					withtowel = 1;
					if (inv[i]->query("equipped"))
						weartowel = 1;
			}
		}
		if( !withtowel)
	    	return notify_fail("��ͯ����Ц����û�а�ë����ôϴ��\n");
    	if (!weartowel)
			return notify_fail("��ͯ����Ц��������Χ��ë���ٽ�ȥ�ɣ���Ҫ�ŵ����ˣ�\n");
	}
	
    if( dir == "north" && ob=present("jin tong", this_object()))
    {
		inv = all_inventory(me);
		for(i=0; i<sizeof(inv); i++)
		{
		    if( (string)(inv[i]->query("id")) == "white towel")
		    {
			tell_object(me,ob->name()+"Ц����Ľ�������ʪ��"+
			  inv[i]->name()+"���˻�ȥ��\n\n\n");	
			destruct(inv[i]);
		    }
		}
    }
    return ::valid_leave(me,dir);
}
