

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",8);

  set ("short", "�����"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG

һ����ֻҪ�ܳ��������ܵõ�������Ҫ��һ�У�
���������ͻ���ȫ�ı䣬���Ѥ�ûԻͣ����˶�ʣ�
ֻ��ϧ���ǵ������������������ǡ�

��Ϊ�����ǽ������ˡ�

LONG);
        set("exits", ([
  "down" : __DIR__"cloud"+(query("floor")-1),
  "up" : __DIR__"cloud"+(query("floor")+1), 
]));
  	set("coor/x",-20);
	set("coor/y",-50);
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
