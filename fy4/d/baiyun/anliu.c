//Created by justdoit at May 2001 
//All Rights Reserved ^_^
inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��̶�׶��£��������飬ˮ���ļ���������һƬ��ڣ���ˮ�������ǿ����
��Ϣһ����˳����ᱻ����ȥ�����������ƺ���Զ����Щ�����⣬һ�ɼ���������
�Ӳ����������˹�ȥ��
LONG
           );
        set("exits", 
           ([ 
       "down" : __DIR__"anliu1",
       "up" : __DIR__"qianlonghu",
        ]));
    set("objects", 
       ([ 
//	     __DIR__"obj/sand" : 1,
        ]));
        set("indoors", "baiyun");
        set("coor/x",10);
    set("coor/y",-1680);
    set("coor/z",0);
    setup();
    replace_program(ROOM);
}
