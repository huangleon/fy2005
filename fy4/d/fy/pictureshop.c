#include <ansi.h>
#include <ansi.h>
inherit ROOM;

void create()
{
    set("short", "ɽˮ��");
    set("long", @LONG
��һ�仭Ժ��ģ��������Ժ�а���Ҳ��Ϊ��ͨ���������Σ���һ�������
��˷·�������ɽ�󴨣��ҿ��ƺ������ڻ���ʯ�֣�һ����������߾��·���
�´�ƮƮ�ľ���������������衣һ���񣬲ŷ�����Щ����ֻ���ıڹ��ŵ���
�����������ν����������˯�𣬰ײ����ַ��˼䡱��
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"swind32",
      ]));

    set("objects", ([
	__DIR__"npc/zhong": 1,
      ]) );

    set("indoors", "fengyun");
    set("coor/x",20);
    set("coor/y",-200);
    set("coor/z",0);
    set("map","fysouth");
    setup();
    replace_program(ROOM);
}

