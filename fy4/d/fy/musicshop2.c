#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "����¥");
    set("long", @LONG
��¥���������ŵĽ��壬��Ȼ�ڷ�����˿��������˵ÿ���й�͵���ʱ����
����޷��Զ������ʱ����д������˿���۵�Сͯ����ӭ�ӡ���˵��ɽ������
���������ڰ��ƽ�������ѧ�գ��ֲ�����֮��ף����Խ��˵���������¥��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"down" : __DIR__"musicshop",
      ]));


    set("indoors", "fengyun");
    set("coor/x",-20);
    set("coor/y",-200);
    set("coor/z",10);
    setup();
    replace_program(ROOM);
}

