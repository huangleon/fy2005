

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",2);

  set ("short", "������"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG

���Ѿ������ѣ����Ѿ����ֺû�����Ϊ����ֻ��һ�֡�
�����Բ����ң��������ң�������Ͳ����ҵ����ѣ������Ͳ���˵�������֡�

LONG);
        set("exits", ([
  "down" : __DIR__"tower1",
  "up" : __DIR__"tower3", 
]));
  	set("coor/x",-10);
	set("coor/y",-40);
	set("coor/z",query("floor")*40);
	setup();
}

/*
 
               (\~~~/)            
               ( ����)        

               (_____)~��      
   
��������������- FengYun - ������
������������annie 10.2003
������dancing_faery@hotmail.com
*/
