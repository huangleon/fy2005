inherit ROOM;

void create()
{
      set("short", "����Ͽ");

	set("long", @LONG
�����ĳ彭�ӻ��������Ľ�ɳ�����ڴ˺ƺƵ���ת�򶫱�����ײ������ѩɽ��
����ѩɽ֮��ľ޴��϶�У�������һ��������Ͽ�ȣ�����Ͽ���԰�Զ��Ρ������
��ɽ���������ѩɽ�������ĺ����ص���ɽ���У����˾�����ƺ����ڲ�������ˮ
�ļ����˼��������˾�����ؼ�һƬ���������������ľ��������Ǻ������ɡ�     
LONG);

         set("exits", ([ 
                "west" : __DIR__"yuema",
                "southeast" : __DIR__"shudao1",
	]));
        set("outdoors", "guanwai");

	set("type","street");
        set("objects", ([
        ]) ); 
	set("coor/x",380);

	set("coor/y",-490);
	set("coor/z",0);
	setup();
	replace_program(ROOM);
}
