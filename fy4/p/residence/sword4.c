

inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",4);

  set ("short", "�ؽ���"+CHINESE_D->chinese_number(query("floor"))+"��");
  set ("long", @LONG

��į��ʲô��һ���˶�����������Ⱦ����죬��į��Ҫ����
��������֪��������һ��ѣ�ȴû��һ���������������ģ���į��Ҫ����
�ⲻ�Ǽ�į����ֻ����о���į���ѡ�
�����ļ�į��һ���������Ŀ��飬һ�����㷢��Ŀ��顣
��Ȼ�ڻ������У�Ҳ��о������ĵĿ��顢������ɥ��

LONG);
        set("exits", ([
  "down" : __DIR__"sword"+(query("floor")-1),
  "up" : __DIR__"sword"+(query("floor")+1), 
]));
  	set("coor/x",-30);
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
