#include <room.h>
inherit ROOM;
void create()
{
	set("short", "��������");
	set("long", @LONG
һ�߽������ӣ�����þ����ʱһˬ��ӭ���Ƿ��޴�ıڻ�����˪������
���繳��һ��������ʿ����������޼�ʻ����һ���������ͼ����
LONG
        );
  	set("exits", ([ /* sizeof() == 4 */
		"center" : __DIR__"groundroom",
	]));

	set("objects", ([
               __DIR__"obj/whipbook" : 1,
                        ]) );
    	set("indoors", "fengyun");
	set("coor/x",-320);
	set("coor/y",100);
	set("coor/z",0);
	set("no_magic",1);
	set("no_spell",1);
    	setup();
}

