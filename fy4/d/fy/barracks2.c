#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "��Ӫ");
    set("long", @LONG
���ƳǶ������Ÿ���һ��Ӫ���أ���Ҫ�����Ͻ��ǵķ������˴�Ϊ��Ӫ������
��Ǯ�������Խ��Խ�󣬾�˵��Ӫ��ͳ���Ȼ����ջ����壬�ѽ���Ϊ�Ϲٽ��
���ã����϶Դ���֪������ȴҲֻ��һֻ�۱�һֻ�ۡ�
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"north" : __DIR__"wcloud5",
      ]));


    set("indoors", "fengyun");
    set("coor/x",-280);
    set("coor/y",-20);
    set("coor/z",0);
    set("map","fywest");
    setup();
    replace_program(ROOM);
}

