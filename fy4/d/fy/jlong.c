inherit ROOM;
void create()
{
    set("short", "������");
    set("long", @LONG
�ذ����Ϻõ�̴��ľ���⻬���Դ���ʪ�����ֱ���һ����̨�������и����ӣ�
��������˰�ë�������绨�����СѾ������æµ�������⣬һ���޴����ͭ
�׼����һ��ϣ�Ѿ�������������ļ�����Ȫˮ��
LONG
    );
    set("exits", ([
	"east" : __DIR__"huanyun2",
	"north" : __DIR__"jlonglang1",
      ]));
    set("objects", ([
	__DIR__"npc/showergirl": 2,
      ]) );
    set("coor/x",-80);
    set("coor/y",-160);
    set("coor/z",0);
    set("map","fysouth");
    setup();
}
