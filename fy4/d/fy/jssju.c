inherit ROOM;
void create()
{
    set("short", "�������");
    set("long", @LONG
��������䲻�ǳ���Ψһ����֣�ȴ�ǳ�������������ĵط����ϰ������
������˵�ǵ����̫�ӵ���ʦ�����Ǿ����������飬���������͵����Ȼ��̰�
ӡˢ������ﲻ���кܶ��ɧ����ϲ����ʫ�ʣ�����һЩ��ǳ�Ĺ����飬�����о�
������ǿ���塣
LONG
    );
    set("exits", ([
	"east" : __DIR__"jidijie",
	"up":	__DIR__"jssju1",
      ]));
    set("objects", ([
	__DIR__"npc/bookseller": 1,
      ]) );

    set("coor/x",-40);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fynorth");
    setup();
    replace_program(ROOM);

}
