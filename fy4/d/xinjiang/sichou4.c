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
  "northwest" : __DIR__"huoyan",
  "southeast" : __DIR__"sichou5",
]));
        set("objects", ([
        __DIR__"npc/trader" : 3,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",100);
	set("coor/y",-60);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
