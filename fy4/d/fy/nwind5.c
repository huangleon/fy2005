#include <ansi.h>
inherit ROOM;
void create()
{
    set("short", HIY"������"NOR);
    set("long", @LONG
�����ţ��ֳ������ţ����Ͻ��Ǳ�ԫ�ţ�������ͬ���Ͻ��ǵ��������ϣ���
ǽͬ��Լ���ɣ�¥�����ӹģ��ƻ������һ������������������������ģ���
���շ��������ӣ����ǻʵ۾�ס�ڹ���ʱ��������¥�ϲ����ӡ�����������Ե�
��ͨ������԰������������˳���š�ѡ��Ůʱ����ѡ��Ů�Ӿ��ɴ��Ž�����
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"southwest" : __DIR__"huantian2",
	"north" : __DIR__"ngate",
	"southeast" : __DIR__"huantian4",
      ]));
    set("outdoors", "fengyun");
    set("coor/x",0);
    set("coor/y",280);
    set("coor/z",0);
    set("map","fynorth");
    setup();
    replace_program(ROOM);
}
