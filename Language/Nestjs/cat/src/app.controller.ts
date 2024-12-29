import { Body, Controller, Get, Param, Req } from '@nestjs/common';
import { AppService } from './app.service';
import { Request } from 'express';

@Controller('cats')
export class AppController {
  constructor(private readonly appService: AppService) {}

  // * localhost:3000/cats/hello
  @Get('hello/:id/:name')
  getHello(@Req() req: Request, @Body() Body, @Param() param: {id: string; name:string},): string {
    //console.log(req);
    console.log(param);
    return this.appService.getHello();
  }
}
