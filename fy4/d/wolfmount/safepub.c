inherit ROOM;

void create()
{
	set("short", "̫ƽ��ջ");

	set("long", @LONG
��ɽ��Ȼһ��Ҳ��̫ƽ��Ψһ�����㴭�����ĵط���ֻ�а�ɽ�����̫ƽ��ջ
�ˡ���������бб�����ſڵ�һ������ƣ�����д�š�̫ƽ��ջ���ĸ����֣����
�ط���û��һ���ջ�����ӡ�ֻ��һ��é�ݴ�������ӣ�������һ������һ������
Ҳû�У�ͨ���Ժ�����������š�
LONG);

	set("type","house");
	set("exits",([
        "northeast":__DIR__"littlesky1",
		"south":__DIR__"pubyard",
		"northwest":__DIR__"gully",
	]) );
    set("valid_startroom", 1);
       set("indoors", "wolfmount");
        set("no_magic",1);
        set("no_fight",1);
	set("objects",([
     		__DIR__"npc/shengyi":1,
    	]) ); 
	set("coor/x",0);
	set("coor/y",0);
	set("coor/z",0);
    	setup();
	replace_program(ROOM);
}
