// Room: dong0
inherit ROOM;
#include <room.h>
void create()
{       
	object          con, item;
        set("short", "����ǰ");
        set("long", @LONG
�˴�һƬ�տ���ǳ���������������һƬ����֮�ϣ�������ʮ��������ɫ��
�ټ�����գ��尸֮�����쳾����̻����£��ƺ����Ա�Ⱥɽ���衣
LONG
        );

       set("exits", ([ /* sizeof() == 4 */
  		"eastup" : __DIR__"gu2",
  		"westdown" : __DIR__"gu4",
 
	])); 
	set("objects", ([
                __DIR__"obj/qinji" : 1,
        ]));

	set("outdoors","tieflag"); 		
         
	set("coor/x",20);
	set("coor/y",0);
	set("coor/z",30);
	setup();

}



void reset()
{
        object          *inv;
        object          con, item;
        int             i;

        ::reset();
        
        con = present("qinji",this_object());
        inv = all_inventory(con);
        if( sizeof(inv) != 1) {
                for(i=sizeof(inv)-1; i>=0; i--) destruct(inv[i]);
                item = new(__DIR__"obj/yaoqin");
                item->move(con);
        }
        
}
