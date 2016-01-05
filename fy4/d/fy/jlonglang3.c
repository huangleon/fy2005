inherit DOOR_ROOM;
#include <room.h>
void create()
{
    set("short", "��������");
    set("long", @LONG
һ�˶�ߣ�ֻ�����˲��е�̴��ľ���ȣ����е����������һЩ�滨��ݡ���
�����������ȵ�һͷð������̴ľ�ذ�����ʪ�ֻ����㼸��Ҫ�������˲Ų��Ử
����
LONG
    );
    set("exits", ([
	"south" : __DIR__"jlonglang2",
	"north" : __DIR__"jlongpool",
      ]));
    set("objects", ([
	__DIR__"npc/smilegirl": 1,
      ]) );
    set("coor/x",-80);
    set("coor/y",-145);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    create_door("north", "door","̴ľ��", "south", DOOR_CLOSED);

}
int valid_leave(object me, string dir)
{
    object *inv;
    object ob;
    int i;
    int withtowel=0;
    int weartowel=0;
    
    if( dir == "north" && ob=present("chu chu", this_object()))
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
	    	return notify_fail("��������Ц����û�а�ë����ôϴ��\n");
    	if (!weartowel)
			return notify_fail("��������Ц��������Χ��ë���ٽ�ȥ�ɣ���Ҫ�ŵ����ˣ�\n");
	}
	
    if( dir == "south" && ob=present("chu chu", this_object()))
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
    return ::valid_leave(me, dir);
}

