inherit ROOM;
void create()
{
        set("short", "˿��֮·");
        set("long", @LONG
˿��֮·������ǳ�������ʱ����˿���������Ʒ�����ڳ����Ժ󣬸�������
��һ��������˿��һƥƥ��У��������鲼��Ƥ��װ����Ȼ��ƺƵ���������̶ӣ�
�����¸ʸ�ԭ��Խ�������룬��������������������������ȣ�����ػ͡�һ����
�����ܲ����۵���·���ƺ�һ������ĺ��Ӷ����Խ�����ڽ��¡�������ǧ�����
ʷ�У�������ʳ�������˵������������ǵİ׹����ڵ�·���ԡ�
LONG
        );
        set("exits", ([ 
  "west" : __DIR__"tulu4",
  "southeast" : __DIR__"sichou2",
]));
/*
        set("objects", ([
        __DIR__"npc/yaren" : 1,
	__DIR__"npc/prince" : 1,
                        ]) );
*/
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",30);
	set("coor/y",-30);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
