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
  "northwest" : __DIR__"sichou4",
  "southeast" : __DIR__"heimiao",
]));
        set("objects", ([
	__DIR__"npc/police1" : 1,
                        ]) );
        //set("no_pk",1);
        
        
        set("outdoors", "xinjiang");
	set("coor/x",110);
	set("coor/y",-70);
	set("coor/z",0);
	setup();
        replace_program(ROOM);
}
