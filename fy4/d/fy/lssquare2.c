inherit ROOM;
void create()
{
    set("short", "���߹㳡");
    set("long", @LONG
�˴���ֻ��һ�����̾����㼯������֮�أ����������������ֶ̼��ˣ���Ҳ��
�˼��У����������д��̸߹٣�Ҳ������ǿ��������������ĺ�ı����С��С����
������֪˭������Ϊ���߹㳡���е��˶��ˣ�Ҳ����ĳ���һ���㳡���ڴ���̯��
�̷������ڹ㳡������˿�ˮ����ν֮������һЩ��������˾���ھͳ��Լ�����
�������裬�ö���֮���������ǵ��������ɴ˵�����
LONG
    );
    set("exits", ([ /* sizeof() == 4 */
	"west" : __DIR__"lssquare1",
	"south" : __DIR__"market",
	"north" : __DIR__"tuji",
	"east" : __DIR__"lssquare3",
      ]));
    set("objects", ([
	//        __DIR__"npc/wanfan" : 1,
      ]) );
    set("resource/water", 1);
    set("liquid",([
	"name":"����ˮ",
	"container":"����"]));

    set("outdoors", "fengyun");
    set("coor/x",160);
    set("coor/y",80);
    set("coor/z",0);
    set("map","fyeast");
    setup();
    replace_program(ROOM);
}
