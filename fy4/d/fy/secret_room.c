inherit ROOM;

void create()
{
    object silver;
    set("short", "��������");
    set("long", @LONG
������һ��խС�����ң������ǰֻ��һ���ƾɵ�С����һЩǬ�ݡ�
LONG
    );

    set("objects", ([
	"/d/fy/obj/biaoyin": 1
      ]) );

    set("exits", ([ /* sizeof() == 4 */
	"up" : __DIR__"gmoney",
      ]));

    set("coor/x",180);
    set("coor/y",-40);
    set("coor/z",-20);
    set("map","fyeast");
    setup();
    silver = present("biaoyin",this_object());
    silver->set_amount(random(1000)+1000);    
    //silver->set("name", "����");
}
